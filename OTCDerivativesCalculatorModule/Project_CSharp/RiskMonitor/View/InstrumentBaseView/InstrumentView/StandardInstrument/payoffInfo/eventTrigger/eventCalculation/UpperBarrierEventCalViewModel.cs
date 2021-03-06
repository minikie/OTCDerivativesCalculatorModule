using System;
using System.Text;
using System.Collections.Generic;
using System.Xml;
using System.Windows.Controls;
using System.ComponentModel;
using System.Collections.ObjectModel;

namespace RiskMonitor
{
    public class UpperBarrierEventCalViewModel : EventCalculationViewModel
    {
 
    
        public UpperBarrierEventCalViewModel() { }
        
    
        #region DateInformationViewModel_
        private ObservableCollection<DateInformationViewModel> dateInformationViewModel_;
        public ObservableCollection<DateInformationViewModel> DateInformationViewModel_
        {
            get { return this.dateInformationViewModel_; }
            set
            {
                if (this.dateInformationViewModel_ != value)
                {
                    this.dateInformationViewModel_ = value;
                    this.NotifyPropertyChanged("DateInformationViewModel_");
                }
            }
        }
        #endregion
        
        #region UpperTrigger_
        private ObservableCollection<string> upperTrigger_;
        public ObservableCollection<string> UpperTrigger_
        {
            get { return this.upperTrigger_; }
            set
            {
                if (this.upperTrigger_ != value)
                {
                    this.upperTrigger_ = value;
                    this.NotifyPropertyChanged("UpperTrigger_");
                }
            }
        }
        #endregion
        
        #region ReferenceCalculationInfoViewModel_
        private ReferenceCalculationInfoViewModel referenceCalculationInfoViewModel_;
        public ReferenceCalculationInfoViewModel ReferenceCalculationInfoViewModel_
        {
            get { return this.referenceCalculationInfoViewModel_; }
            set
            {
                if (this.referenceCalculationInfoViewModel_ != value)
                {
                    this.referenceCalculationInfoViewModel_ = value;
                    this.NotifyPropertyChanged("ReferenceCalculationInfoViewModel_");
                }
            }
        }
        #endregion
        
        public override void buildXml(System.Xml.XmlWriter xmlWriter)
        {
            xmlWriter.WriteStartElement("eventCalculation");
                xmlWriter.WriteElementString("type" , "upperBarrierEventCal");
                xmlWriter.WriteStartElement("upperBarrierEventCal");

                    foreach (var item in dateInformationViewModel_)
                    {
                        item.buildXml(xmlWriter);    
                    }

                    foreach (var item in this.upperTrigger_)
                    {
                        xmlWriter.WriteElementString("upperTrigger", item);    
                    }
                    
                    referenceCalculationInfoViewModel_.buildXml(xmlWriter);
                    
                xmlWriter.WriteEndElement();
            xmlWriter.WriteEndElement();
        }
        
        public override void setFromXml(System.Xml.XmlNode node)
        {
            throw new NotImplementedException();
        }
        
        public override void setFromSerial(FpmlSerializedCSharp.ISerialized serial_Class)
        {
            FpmlSerializedCSharp.EventCalculation serial_EventCalculation = serial_Class as FpmlSerializedCSharp.EventCalculation;
            FpmlSerializedCSharp.UpperBarrierEventCal serial_UpperBarrierEventCal = serial_EventCalculation.UpperBarrierEventCal_;
        
            List<FpmlSerializedCSharp.DateInformation> serial_dateInformation = serial_UpperBarrierEventCal.DateInformation_;
            this.dateInformationViewModel_ = new ObservableCollection<DateInformationViewModel>();
            foreach (var item in serial_dateInformation)
            {
                string type = item.Type_.ValueStr;
                DateInformationViewModel viewModel = DateInformationViewModel.CreateDateInformation(type);
                viewModel.setFromSerial(item);
                this.dateInformationViewModel_.Add(viewModel);
            }
            
            this.upperTrigger_ = new ObservableCollection<string>();

            foreach (var item in serial_UpperBarrierEventCal.UpperTrigger_)
            {
                this.upperTrigger_.Add(item.ValueStr);
            }
            
            FpmlSerializedCSharp.ReferenceCalculationInfo serial_referenceCalculationInfo = serial_UpperBarrierEventCal.ReferenceCalculationInfo_;
            this.referenceCalculationInfoViewModel_.setFromSerial(serial_referenceCalculationInfo);
            
            //this.view_ = new UpperBarrierEventCalView();
            this.view_.DataContext = this;
        }
        
    
    }
    
}

