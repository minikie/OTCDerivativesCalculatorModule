using System;
using System.Text;
using System.Collections.Generic;
using System.Xml;
using System.Windows.Controls;
using System.ComponentModel;
using System.Collections.ObjectModel;

namespace Excel_Interface
{
    public abstract class Excel_underlyingModel_paraViewModel : IXmlData
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
        
        public Excel_underlyingModel_paraViewModel() { }
        
        #region Excel_type_
        private string excel_type_;
        public string Excel_type_
        {
            get { return this.excel_type_; }
            set
            {
                if (this.excel_type_ != value)
                {
                    this.excel_type_ = value;
                    this.NotifyPropertyChanged("Excel_type_");
                }
            }
        }
        #endregion
        
        #region Excel_geometricBMViewModel_
        private Excel_geometricBMViewModel excel_geometricBMViewModel_;
        public Excel_geometricBMViewModel Excel_geometricBMViewModel_
        {
            get { return this.excel_geometricBMViewModel_; }
            set
            {
                if (this.excel_geometricBMViewModel_ != value)
                {
                    this.excel_geometricBMViewModel_ = value;
                    this.NotifyPropertyChanged("Excel_geometricBMViewModel_");
                }
            }
        }
        #endregion
        
        #region Excel_hullWhiteOneFactorViewModel_
        private Excel_hullWhiteOneFactorViewModel excel_hullWhiteOneFactorViewModel_;
        public Excel_hullWhiteOneFactorViewModel Excel_hullWhiteOneFactorViewModel_
        {
            get { return this.excel_hullWhiteOneFactorViewModel_; }
            set
            {
                if (this.excel_hullWhiteOneFactorViewModel_ != value)
                {
                    this.excel_hullWhiteOneFactorViewModel_ = value;
                    this.NotifyPropertyChanged("Excel_hullWhiteOneFactorViewModel_");
                }
            }
        }
        #endregion
        
        #region Excel_forwardModelViewModel_
        private Excel_forwardModelViewModel excel_forwardModelViewModel_;
        public Excel_forwardModelViewModel Excel_forwardModelViewModel_
        {
            get { return this.excel_forwardModelViewModel_; }
            set
            {
                if (this.excel_forwardModelViewModel_ != value)
                {
                    this.excel_forwardModelViewModel_ = value;
                    this.NotifyPropertyChanged("Excel_forwardModelViewModel_");
                }
            }
        }
        #endregion
        
        public string choiceStr_0;
        
    
        public abstract void buildXml(System.Xml.XmlWriter xmlWriter);
        public abstract void setFromXml(System.Xml.XmlNode node);
        public abstract void setFromSerial(FpmlSerializedCSharp.ISerialized serial_Class);
        
    
        public static Excel_underlyingModel_paraViewModel CreateExcel_underlyingModel_para(string typeStr)
        {
            if ( typeStr == "excel_geometricBM")
            {
                return new Excel_geometricBMViewModel();
            }
            else if ( typeStr == "excel_hullWhiteOneFactor")
            {
                return new Excel_hullWhiteOneFactorViewModel();
            }
            else if ( typeStr == "excel_forwardModel")
            {
                return new Excel_forwardModelViewModel();
            }
            else
            {
            throw new NotImplementedException();
            }
        }
        
        
    
    }
    
}

