using System;
using System.Text;
using System.Collections.Generic;
using System.Xml;
using System.Windows.Controls;
using System.ComponentModel;
using System.Collections.ObjectModel;

namespace Excel_Interface
{
    public class ReferenceInformationViewModel : IXmlData
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
        
        public ReferenceInformationViewModel() { }
        
        #region EntityName_
        private string entityName_;
        public string EntityName_
        {
            get { return this.entityName_; }
            set
            {
                if (this.entityName_ != value)
                {
                    this.entityName_ = value;
                    this.NotifyPropertyChanged("EntityName_");
                }
            }
        }
        #endregion
        
        #region EntityId_
        private string entityId_;
        public string EntityId_
        {
            get { return this.entityId_; }
            set
            {
                if (this.entityId_ != value)
                {
                    this.entityId_ = value;
                    this.NotifyPropertyChanged("EntityId_");
                }
            }
        }
        #endregion
        
        
    
        public  void buildXml(System.Xml.XmlWriter xmlWriter)
        {
            xmlWriter.WriteStartElement("iXmlData");
                xmlWriter.WriteElementString("excel_type" , "referenceInformation");
                xmlWriter.WriteStartElement("referenceInformation");
                    xmlWriter.WriteElementString("entityName" , this.entityName_);
                    
                    xmlWriter.WriteElementString("entityId" , this.entityId_);
                    
                xmlWriter.WriteEndElement();
            xmlWriter.WriteEndElement();
        }
        
        public  void setFromXml(System.Xml.XmlNode node)
        {
            throw new NotImplementedException();
        }
        
        public  Control view()
        {
            Control v = new ReferenceInformationView();
            v.DataContext = this;
            return v;
        }
        
        public  void setFromSerial(FpmlSerializedCSharp.ISerialized serial_Class)
        {
            FpmlSerializedCSharp.ReferenceInformation serial_ReferenceInformation = serial_Class as FpmlSerializedCSharp.ReferenceInformation;
        
            this.entityName_ = serial_ReferenceInformation.EntityName_.ValueStr;
            
            this.entityId_ = serial_ReferenceInformation.EntityId_.ValueStr;
            
        }
        
        
    
        
    
        
    
    }
    
}

