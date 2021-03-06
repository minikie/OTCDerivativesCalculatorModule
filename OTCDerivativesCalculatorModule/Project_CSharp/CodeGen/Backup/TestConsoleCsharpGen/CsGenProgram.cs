﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml.Schema;
using System.IO;
using CSharpCodeGen;

namespace TestConsole
{
    class Program
    {
        public const string rootFolder = @"D:\Project File\OTCDerivativesCalculatorModule\Project_CSharp\XmlBuilder\XmlSerializedClass\";
        public const string relFolder = @"GenCsharpClass\";
        public const string xsdFolder = @"D:\Project File\OTCDerivativesCalculatorModule\Xml\XSD\confirmation\";

        private static List<string> built_in_type =
                                new List<string>() {"anyURI","base64Binary","boolean","byte","date",
                                                    "dateTime","decimal","double","duration","ENTITIES",
                                                    "ENTITY","float","gDay","gMonth","gMonthDay",
                                                    "gYear","gYearMonth","hexBinary","ID","IDREF",
                                                    "IDREFS","int","integer","language","long",
                                                    "Name","NCName","negativeInteger","NMTOKEN",
                                                    "NMTOKENS","nonNegativeInteger","nonPositiveInteger","normalizedString","NOTATION",
                                                    "positiveInteger","QName","short","string","time",
                                                    "token","unsignedByte","unsignedInt","unsignedLong","unsignedShort"
                                                  
                                                    }; //static 외부

        // Dictionary( name , fileName )
        private static Dictionary<string, string> includePath = new Dictionary<string, string>();
        // Dictionary( name , Type ,substitutionGroupType)
        private static Dictionary<string, string> elementRef = new Dictionary<string, string>();

        private static Dictionary<string, XmlSchemaGroup> elementGroupRef = new Dictionary<string, XmlSchemaGroup>();
        // 중복된 Key값때문에 배열로 감.
        private static List<KeyValuePair<string, string>> elementSubstitutionRef = new List<KeyValuePair<string, string>>();

        static void Main(string[] args)
        {

            string built_in_type_subfoler = "built_in_type";
            Variable.built_in_type = built_in_type;
            ClassGen.built_in_type = built_in_type;

            Wrapper.makeTapStr(4);

            string subBuiltInPath = System.IO.Path.Combine(rootFolder, built_in_type_subfoler);
            System.IO.Directory.CreateDirectory(subBuiltInPath);
            foreach (string item in built_in_type)
            {
                includePath.Add(item, built_in_type_subfoler);
            }


            foreach (string item in built_in_type)
            {
                XsdBuiltInVariable xbv = new XsdBuiltInVariable(item);

                using (var writer = new StringWriter())
                {
                    writer.WriteLine(xbv.Code);
                    File.WriteAllText(Path.Combine(subBuiltInPath, xbv.CName + ".cs"), writer.GetStringBuilder().ToString());
                }
            }



            //--------------------------------------------------------
            System.IO.DriveInfo di = new System.IO.DriveInfo(@"D:\");
            Console.WriteLine(di.TotalFreeSpace);
            Console.WriteLine(di.VolumeLabel);

            // Get the root directory and print out some information about it.
            System.IO.DirectoryInfo dirInfo = new DirectoryInfo(xsdFolder);
            Console.WriteLine(dirInfo.Attributes.ToString());

            System.IO.FileInfo[] fileNames = dirInfo.GetFiles("*.xsd");

            var rootAllIncludeWriter = new StringWriter();

            foreach (System.IO.FileInfo fi in fileNames)
            {
                RegistEleForRefAttribute(fi.Name);
            }
            foreach (System.IO.FileInfo fi in fileNames)
            {
                Console.WriteLine("{0}: {1}: {2}", fi.Name, fi.LastAccessTime, fi.Length);
                Generation(fi.Name);
                string directoryName = fi.Name.Replace(".xsd", "");
            }
        }

        private static void Generation(string xsdFileName)
        {
            string subfoler = xsdFileName.Replace(".xsd", "");
            string subBuiltInPath = System.IO.Path.Combine(rootFolder, subfoler);
            System.IO.Directory.CreateDirectory(subBuiltInPath);

            XmlSchema rootSchema = GetSchemaFromFile(xsdFileName);

            bool noUseFile = false;

            foreach (XmlSchemaObject item in rootSchema.Items)
            {
                var csWriter = new StringWriter();

                string schemaObjectName = "";

                if (item is XmlSchemaElement)
                {
                    XmlSchemaElement xe = item as XmlSchemaElement;
                    schemaObjectName = xe.Name + "NoUseFile";
                    noUseFile = true;
                }
                else if (item is XmlSchemaComplexType)
                {
                    XmlSchemaComplexType xsct = item as XmlSchemaComplexType;
                    CSharpCodeGen.Generator gen = new Generator(xsct, elementRef, includePath, elementSubstitutionRef, elementGroupRef);
                    gen.makeCode();
                    csWriter.WriteLine(gen.CsCode);
                    
                    schemaObjectName = xsct.Name;
                }
                else if (item is XmlSchemaSimpleType)
                {
                    XmlSchemaSimpleType xsst = item as XmlSchemaSimpleType;
                    CSharpCodeGen.GeneratorSimple gen = new GeneratorSimple(xsst);
                    csWriter.WriteLine(gen.CsCode);
                    schemaObjectName = xsst.Name;
                }

                if (!noUseFile)
                {
                    File.WriteAllText(Path.Combine(subBuiltInPath, schemaObjectName + ".cs"), csWriter.GetStringBuilder().ToString());
                }
            }
        }

        private static void RegistEleForRefAttribute(string xsdFileName)
        {
            XmlSchema rootSchema = GetSchemaFromFile(xsdFileName);
            string subfolerName = xsdFileName.Replace(".xsd", "");

            foreach (XmlSchemaObject item in rootSchema.Items)
            {
                if (item is XmlSchemaSimpleType)
                {
                    XmlSchemaSimpleType xsst = item as XmlSchemaSimpleType;
                    includePath.Add(xsst.Name, subfolerName);

                }
                else if (item is XmlSchemaComplexType)
                {
                    XmlSchemaComplexType xsct = item as XmlSchemaComplexType;

                    includePath.Add(xsct.Name, subfolerName);
                }
                else if (item is XmlSchemaElement)
                {
                    XmlSchemaElement xe = item as XmlSchemaElement;
                    if (xe.RefName.IsEmpty)
                    {
                        //string nametype = xe.ElementSchemaType.Name;
                        //string nametype2 = xe.SchemaTypeName.Name;

                        //ref 가 없는 element만 넣어서 나중에 이 List를 뒤져서 Type을 알아냄
                        elementRef.Add(xe.Name, xe.SchemaTypeName.Name);

                        //ref 가 없고 substitutionGroup이 있는 element만 넣어서 나중에 이 List를 뒤져서 substitution 에 추가함
                        if (!xe.SubstitutionGroup.IsEmpty)
                        {
                            KeyValuePair<string, string> pair = new KeyValuePair<string, string>(xe.SubstitutionGroup.Name, xe.Name);
                            elementSubstitutionRef.Add(pair);
                        }

                    }
                }
                else if (item is XmlSchemaGroup)
                {
                    XmlSchemaGroup xe = item as XmlSchemaGroup;
                    elementGroupRef.Add(xe.Name, xe);
                }

            }
        }
        private static XmlSchema GetSchemaFromFile(string fileName)
        {
            using (var fs = new FileStream(Path.Combine(xsdFolder, fileName), FileMode.Open))
                return XmlSchema.Read(fs, null);
        }

    }
}
