using System;
using System.Text;
using System.Collections.Generic;
using System.Xml;
using System.Windows.Controls;
using System.ComponentModel;
using System.Collections.ObjectModel;

namespace Excel_Interface
{
    public class Excel_noneOptionViewModel : Excel_additionalOptionViewModel
    {
        #region Event
        public event PropertyChangedEventHandler PropertyChanged;
        
        protected void NotifyPropertyChanged(string propertyName)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
            }
        }
        #endregion
        
        public Excel_noneOptionViewModel() 
        {
            this.optionType_ = "noneOption";
        }
    
        public override void buildXml(System.Xml.XmlWriter xmlWriter)
        {
            xmlWriter.WriteStartElement("excel_additionalOption");
                xmlWriter.WriteElementString("excel_type" , "excel_noneOption");
                xmlWriter.WriteStartElement("excel_noneOption");
                    xmlWriter.WriteElementString("optionType", this.optionType_);
                xmlWriter.WriteEndElement();
            xmlWriter.WriteEndElement();
        }
        
        public override void setFromXml(System.Xml.XmlNode node)
        {
            throw new NotImplementedException();
        }
        
        public override void setFromSerial(FpmlSerializedCSharp.ISerialized serial_Class)
        {
            FpmlSerializedCSharp.Excel_additionalOption serial_Excel_additionalOption = serial_Class as FpmlSerializedCSharp.Excel_additionalOption;
            FpmlSerializedCSharp.Excel_noneOption serial_Excel_noneOption = serial_Excel_additionalOption.Excel_noneOption_;

            this.optionType_ = serial_Excel_noneOption.OptionType_.ValueStr;
        }
        
    }
    
}

