using System;
using System.Text;
using System.Collections.Generic;
using System.Xml;
using System.Windows.Controls;
using System.ComponentModel;
using System.Collections.ObjectModel;

namespace Excel_Interface
{
    public class VanillaSwapPayoffViewModel : SwapPayoffInfoViewModel
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
        
        public VanillaSwapPayoffViewModel() { }
        
        #region RecieveSwapPartViewModel_
        private RecieveSwapPartViewModel recieveSwapPartViewModel_;
        public RecieveSwapPartViewModel RecieveSwapPartViewModel_
        {
            get { return this.recieveSwapPartViewModel_; }
            set
            {
                if (this.recieveSwapPartViewModel_ != value)
                {
                    this.recieveSwapPartViewModel_ = value;
                    this.NotifyPropertyChanged("RecieveSwapPartViewModel_");
                }
            }
        }
        #endregion
        
        #region PaySwapPartViewModel_
        private PaySwapPartViewModel paySwapPartViewModel_;
        public PaySwapPartViewModel PaySwapPartViewModel_
        {
            get { return this.paySwapPartViewModel_; }
            set
            {
                if (this.paySwapPartViewModel_ != value)
                {
                    this.paySwapPartViewModel_ = value;
                    this.NotifyPropertyChanged("PaySwapPartViewModel_");
                }
            }
        }
        #endregion
        
        
    
        public override void buildXml(System.Xml.XmlWriter xmlWriter)
        {
            xmlWriter.WriteStartElement("swapPayoffInfo");
                xmlWriter.WriteElementString("type" , "vanillaSwapPayoff");
                xmlWriter.WriteStartElement("vanillaSwapPayoff");
                    recieveSwapPartViewModel_.buildXml(xmlWriter);
                    
                    paySwapPartViewModel_.buildXml(xmlWriter);
                    
                xmlWriter.WriteEndElement();
            xmlWriter.WriteEndElement();
        }
        
        public override void setFromXml(System.Xml.XmlNode node)
        {
            throw new NotImplementedException();
        }
        
        public override Control view()
        {
            Control v = new VanillaSwapPayoffView();
            v.DataContext = this;
            return v;
        }
        
        public override void setFromSerial(FpmlSerializedCSharp.ISerialized serial_Class)
        {
            FpmlSerializedCSharp.SwapPayoffInfo serial_SwapPayoffInfo = serial_Class as FpmlSerializedCSharp.SwapPayoffInfo;
            FpmlSerializedCSharp.VanillaSwapPayoff serial_VanillaSwapPayoff = serial_SwapPayoffInfo.VanillaSwapPayoff_;
        
            FpmlSerializedCSharp.RecieveSwapPart serial_recieveSwapPart = serial_VanillaSwapPayoff.RecieveSwapPart_;
            string recieveSwapParttype = serial_recieveSwapPart.Excel_type_.ValueStr;
            this.recieveSwapPartViewModel_ = RecieveSwapPartViewModel.CreateRecieveSwapPart(recieveSwapParttype);
            this.recieveSwapPartViewModel_.setFromSerial(serial_recieveSwapPart);
            
            FpmlSerializedCSharp.PaySwapPart serial_paySwapPart = serial_VanillaSwapPayoff.PaySwapPart_;
            string paySwapParttype = serial_paySwapPart.Excel_type_.ValueStr;
            this.paySwapPartViewModel_ = PaySwapPartViewModel.CreatePaySwapPart(paySwapParttype);
            this.paySwapPartViewModel_.setFromSerial(serial_paySwapPart);
            
        }
        
        
    
            
            
            
            
        
    
        
    
    }
    
}

