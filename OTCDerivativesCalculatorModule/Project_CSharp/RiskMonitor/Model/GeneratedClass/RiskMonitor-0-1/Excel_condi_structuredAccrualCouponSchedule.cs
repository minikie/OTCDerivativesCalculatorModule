using System;
using System.Text;
using System.Collections.Generic;
using System.Xml;

namespace FpmlSerializedCSharp
{
    public class Excel_condi_structuredAccrualCouponSchedule : ISerialized
    {
        public Excel_condi_structuredAccrualCouponSchedule() { }
        public Excel_condi_structuredAccrualCouponSchedule(XmlNode xmlNode)
        : base(xmlNode)
        {
            XmlNode eventDateNode = xmlNode.SelectSingleNode("eventDate");
            
            if (eventDateNode != null)
            {
                if (eventDateNode.Attributes["href"] != null || eventDateNode.Attributes["id"] != null) 
                {
                    if (eventDateNode.Attributes["id"] != null) 
                    {
                        eventDateIDRef_ = eventDateNode.Attributes["id"].Value;
                        XsdTypeToken ob = new XsdTypeToken(eventDateNode);
                        IDManager.SetID(eventDateIDRef_, ob);
                    }
                    else if (eventDateNode.Attributes["href"] != null)
                    {
                        eventDateIDRef_ = eventDateNode.Attributes["href"].Value;
                    }
                    else
                    {
                        eventDate_ = new XsdTypeToken(eventDateNode);
                    }
                }
                else
                {
                    eventDate_ = new XsdTypeToken(eventDateNode);
                }
            }
            
        
            XmlNode range1DNode = xmlNode.SelectSingleNode("range1D");
            
            if (range1DNode != null)
            {
                if (range1DNode.Attributes["href"] != null || range1DNode.Attributes["id"] != null) 
                {
                    if (range1DNode.Attributes["id"] != null) 
                    {
                        range1DIDRef_ = range1DNode.Attributes["id"].Value;
                        Range1D ob = new Range1D(range1DNode);
                        IDManager.SetID(range1DIDRef_, ob);
                    }
                    else if (range1DNode.Attributes["href"] != null)
                    {
                        range1DIDRef_ = range1DNode.Attributes["href"].Value;
                    }
                    else
                    {
                        range1D_ = new Range1D(range1DNode);
                    }
                }
                else
                {
                    range1D_ = new Range1D(range1DNode);
                }
            }
            
        
            XmlNode excel_returnCalcInfoNode = xmlNode.SelectSingleNode("excel_returnCalcInfo");
            
            if (excel_returnCalcInfoNode != null)
            {
                if (excel_returnCalcInfoNode.Attributes["href"] != null || excel_returnCalcInfoNode.Attributes["id"] != null) 
                {
                    if (excel_returnCalcInfoNode.Attributes["id"] != null) 
                    {
                        excel_returnCalcInfoIDRef_ = excel_returnCalcInfoNode.Attributes["id"].Value;
                        Excel_returnCalcInfo ob = new Excel_returnCalcInfo(excel_returnCalcInfoNode);
                        IDManager.SetID(excel_returnCalcInfoIDRef_, ob);
                    }
                    else if (excel_returnCalcInfoNode.Attributes["href"] != null)
                    {
                        excel_returnCalcInfoIDRef_ = excel_returnCalcInfoNode.Attributes["href"].Value;
                    }
                    else
                    {
                        excel_returnCalcInfo_ = new Excel_returnCalcInfo(excel_returnCalcInfoNode);
                    }
                }
                else
                {
                    excel_returnCalcInfo_ = new Excel_returnCalcInfo(excel_returnCalcInfoNode);
                }
            }
            
        
            XmlNode dayCounterNode = xmlNode.SelectSingleNode("dayCounter");
            
            if (dayCounterNode != null)
            {
                if (dayCounterNode.Attributes["href"] != null || dayCounterNode.Attributes["id"] != null) 
                {
                    if (dayCounterNode.Attributes["id"] != null) 
                    {
                        dayCounterIDRef_ = dayCounterNode.Attributes["id"].Value;
                        XsdTypeToken ob = new XsdTypeToken(dayCounterNode);
                        IDManager.SetID(dayCounterIDRef_, ob);
                    }
                    else if (dayCounterNode.Attributes["href"] != null)
                    {
                        dayCounterIDRef_ = dayCounterNode.Attributes["href"].Value;
                    }
                    else
                    {
                        dayCounter_ = new XsdTypeToken(dayCounterNode);
                    }
                }
                else
                {
                    dayCounter_ = new XsdTypeToken(dayCounterNode);
                }
            }
            
        
            XmlNode calculationStartDateNode = xmlNode.SelectSingleNode("calculationStartDate");
            
            if (calculationStartDateNode != null)
            {
                if (calculationStartDateNode.Attributes["href"] != null || calculationStartDateNode.Attributes["id"] != null) 
                {
                    if (calculationStartDateNode.Attributes["id"] != null) 
                    {
                        calculationStartDateIDRef_ = calculationStartDateNode.Attributes["id"].Value;
                        XsdTypeToken ob = new XsdTypeToken(calculationStartDateNode);
                        IDManager.SetID(calculationStartDateIDRef_, ob);
                    }
                    else if (calculationStartDateNode.Attributes["href"] != null)
                    {
                        calculationStartDateIDRef_ = calculationStartDateNode.Attributes["href"].Value;
                    }
                    else
                    {
                        calculationStartDate_ = new XsdTypeToken(calculationStartDateNode);
                    }
                }
                else
                {
                    calculationStartDate_ = new XsdTypeToken(calculationStartDateNode);
                }
            }
            
        
            XmlNode calculationEndDateNode = xmlNode.SelectSingleNode("calculationEndDate");
            
            if (calculationEndDateNode != null)
            {
                if (calculationEndDateNode.Attributes["href"] != null || calculationEndDateNode.Attributes["id"] != null) 
                {
                    if (calculationEndDateNode.Attributes["id"] != null) 
                    {
                        calculationEndDateIDRef_ = calculationEndDateNode.Attributes["id"].Value;
                        XsdTypeToken ob = new XsdTypeToken(calculationEndDateNode);
                        IDManager.SetID(calculationEndDateIDRef_, ob);
                    }
                    else if (calculationEndDateNode.Attributes["href"] != null)
                    {
                        calculationEndDateIDRef_ = calculationEndDateNode.Attributes["href"].Value;
                    }
                    else
                    {
                        calculationEndDate_ = new XsdTypeToken(calculationEndDateNode);
                    }
                }
                else
                {
                    calculationEndDate_ = new XsdTypeToken(calculationEndDateNode);
                }
            }
            
        
            XmlNode paymentDateNode = xmlNode.SelectSingleNode("paymentDate");
            
            if (paymentDateNode != null)
            {
                if (paymentDateNode.Attributes["href"] != null || paymentDateNode.Attributes["id"] != null) 
                {
                    if (paymentDateNode.Attributes["id"] != null) 
                    {
                        paymentDateIDRef_ = paymentDateNode.Attributes["id"].Value;
                        XsdTypeToken ob = new XsdTypeToken(paymentDateNode);
                        IDManager.SetID(paymentDateIDRef_, ob);
                    }
                    else if (paymentDateNode.Attributes["href"] != null)
                    {
                        paymentDateIDRef_ = paymentDateNode.Attributes["href"].Value;
                    }
                    else
                    {
                        paymentDate_ = new XsdTypeToken(paymentDateNode);
                    }
                }
                else
                {
                    paymentDate_ = new XsdTypeToken(paymentDateNode);
                }
            }
            
        
            XmlNode detailScheduleTypeNode = xmlNode.SelectSingleNode("detailScheduleType");
            
            if (detailScheduleTypeNode != null)
            {
                if (detailScheduleTypeNode.Attributes["href"] != null || detailScheduleTypeNode.Attributes["id"] != null) 
                {
                    if (detailScheduleTypeNode.Attributes["id"] != null) 
                    {
                        detailScheduleTypeIDRef_ = detailScheduleTypeNode.Attributes["id"].Value;
                        XsdTypeToken ob = new XsdTypeToken(detailScheduleTypeNode);
                        IDManager.SetID(detailScheduleTypeIDRef_, ob);
                    }
                    else if (detailScheduleTypeNode.Attributes["href"] != null)
                    {
                        detailScheduleTypeIDRef_ = detailScheduleTypeNode.Attributes["href"].Value;
                    }
                    else
                    {
                        detailScheduleType_ = new XsdTypeToken(detailScheduleTypeNode);
                    }
                }
                else
                {
                    detailScheduleType_ = new XsdTypeToken(detailScheduleTypeNode);
                }
            }
            
        
            XmlNode descriptionNode = xmlNode.SelectSingleNode("description");
            
            if (descriptionNode != null)
            {
                if (descriptionNode.Attributes["href"] != null || descriptionNode.Attributes["id"] != null) 
                {
                    if (descriptionNode.Attributes["id"] != null) 
                    {
                        descriptionIDRef_ = descriptionNode.Attributes["id"].Value;
                        XsdTypeToken ob = new XsdTypeToken(descriptionNode);
                        IDManager.SetID(descriptionIDRef_, ob);
                    }
                    else if (descriptionNode.Attributes["href"] != null)
                    {
                        descriptionIDRef_ = descriptionNode.Attributes["href"].Value;
                    }
                    else
                    {
                        description_ = new XsdTypeToken(descriptionNode);
                    }
                }
                else
                {
                    description_ = new XsdTypeToken(descriptionNode);
                }
            }
            
        
        }
        
    
        #region EventDate_
        private XsdTypeToken eventDate_;
        public XsdTypeToken EventDate_
        {
            get
            {
                if (this.eventDate_ != null)
                {
                    return this.eventDate_; 
                }
                else if (this.eventDateIDRef_ != null)
                {
                    eventDate_ = IDManager.getID(eventDateIDRef_) as XsdTypeToken;
                    return this.eventDate_; 
                }
                else
                {
                    throw new Exception( "eventDate_Node no exist!");
                }
            }
            set
            {
                if (this.eventDate_ != value)
                {
                    this.eventDate_ = value;
                }
            }
        }
        #endregion
        
        public string eventDateIDRef_ { get; set; }
        #region Range1D_
        private Range1D range1D_;
        public Range1D Range1D_
        {
            get
            {
                if (this.range1D_ != null)
                {
                    return this.range1D_; 
                }
                else if (this.range1DIDRef_ != null)
                {
                    range1D_ = IDManager.getID(range1DIDRef_) as Range1D;
                    return this.range1D_; 
                }
                else
                {
                    throw new Exception( "range1D_Node no exist!");
                }
            }
            set
            {
                if (this.range1D_ != value)
                {
                    this.range1D_ = value;
                }
            }
        }
        #endregion
        
        public string range1DIDRef_ { get; set; }
        #region Excel_returnCalcInfo_
        private Excel_returnCalcInfo excel_returnCalcInfo_;
        public Excel_returnCalcInfo Excel_returnCalcInfo_
        {
            get
            {
                if (this.excel_returnCalcInfo_ != null)
                {
                    return this.excel_returnCalcInfo_; 
                }
                else if (this.excel_returnCalcInfoIDRef_ != null)
                {
                    excel_returnCalcInfo_ = IDManager.getID(excel_returnCalcInfoIDRef_) as Excel_returnCalcInfo;
                    return this.excel_returnCalcInfo_; 
                }
                else
                {
                    throw new Exception( "excel_returnCalcInfo_Node no exist!");
                }
            }
            set
            {
                if (this.excel_returnCalcInfo_ != value)
                {
                    this.excel_returnCalcInfo_ = value;
                }
            }
        }
        #endregion
        
        public string excel_returnCalcInfoIDRef_ { get; set; }
        #region DayCounter_
        private XsdTypeToken dayCounter_;
        public XsdTypeToken DayCounter_
        {
            get
            {
                if (this.dayCounter_ != null)
                {
                    return this.dayCounter_; 
                }
                else if (this.dayCounterIDRef_ != null)
                {
                    dayCounter_ = IDManager.getID(dayCounterIDRef_) as XsdTypeToken;
                    return this.dayCounter_; 
                }
                else
                {
                    throw new Exception( "dayCounter_Node no exist!");
                }
            }
            set
            {
                if (this.dayCounter_ != value)
                {
                    this.dayCounter_ = value;
                }
            }
        }
        #endregion
        
        public string dayCounterIDRef_ { get; set; }
        #region CalculationStartDate_
        private XsdTypeToken calculationStartDate_;
        public XsdTypeToken CalculationStartDate_
        {
            get
            {
                if (this.calculationStartDate_ != null)
                {
                    return this.calculationStartDate_; 
                }
                else if (this.calculationStartDateIDRef_ != null)
                {
                    calculationStartDate_ = IDManager.getID(calculationStartDateIDRef_) as XsdTypeToken;
                    return this.calculationStartDate_; 
                }
                else
                {
                    throw new Exception( "calculationStartDate_Node no exist!");
                }
            }
            set
            {
                if (this.calculationStartDate_ != value)
                {
                    this.calculationStartDate_ = value;
                }
            }
        }
        #endregion
        
        public string calculationStartDateIDRef_ { get; set; }
        #region CalculationEndDate_
        private XsdTypeToken calculationEndDate_;
        public XsdTypeToken CalculationEndDate_
        {
            get
            {
                if (this.calculationEndDate_ != null)
                {
                    return this.calculationEndDate_; 
                }
                else if (this.calculationEndDateIDRef_ != null)
                {
                    calculationEndDate_ = IDManager.getID(calculationEndDateIDRef_) as XsdTypeToken;
                    return this.calculationEndDate_; 
                }
                else
                {
                    throw new Exception( "calculationEndDate_Node no exist!");
                }
            }
            set
            {
                if (this.calculationEndDate_ != value)
                {
                    this.calculationEndDate_ = value;
                }
            }
        }
        #endregion
        
        public string calculationEndDateIDRef_ { get; set; }
        #region PaymentDate_
        private XsdTypeToken paymentDate_;
        public XsdTypeToken PaymentDate_
        {
            get
            {
                if (this.paymentDate_ != null)
                {
                    return this.paymentDate_; 
                }
                else if (this.paymentDateIDRef_ != null)
                {
                    paymentDate_ = IDManager.getID(paymentDateIDRef_) as XsdTypeToken;
                    return this.paymentDate_; 
                }
                else
                {
                    throw new Exception( "paymentDate_Node no exist!");
                }
            }
            set
            {
                if (this.paymentDate_ != value)
                {
                    this.paymentDate_ = value;
                }
            }
        }
        #endregion
        
        public string paymentDateIDRef_ { get; set; }
        #region DetailScheduleType_
        private XsdTypeToken detailScheduleType_;
        public XsdTypeToken DetailScheduleType_
        {
            get
            {
                if (this.detailScheduleType_ != null)
                {
                    return this.detailScheduleType_; 
                }
                else if (this.detailScheduleTypeIDRef_ != null)
                {
                    detailScheduleType_ = IDManager.getID(detailScheduleTypeIDRef_) as XsdTypeToken;
                    return this.detailScheduleType_; 
                }
                else
                {
                    throw new Exception( "detailScheduleType_Node no exist!");
                }
            }
            set
            {
                if (this.detailScheduleType_ != value)
                {
                    this.detailScheduleType_ = value;
                }
            }
        }
        #endregion
        
        public string detailScheduleTypeIDRef_ { get; set; }
        #region Description_
        private XsdTypeToken description_;
        public XsdTypeToken Description_
        {
            get
            {
                if (this.description_ != null)
                {
                    return this.description_; 
                }
                else if (this.descriptionIDRef_ != null)
                {
                    description_ = IDManager.getID(descriptionIDRef_) as XsdTypeToken;
                    return this.description_; 
                }
                else
                {
                    throw new Exception( "description_Node no exist!");
                }
            }
            set
            {
                if (this.description_ != value)
                {
                    this.description_ = value;
                }
            }
        }
        #endregion
        
        public string descriptionIDRef_ { get; set; }
        
    
        
    
    }
    
}
