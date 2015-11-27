using System;
using System.Text;
using System.Collections.Generic;
using System.Xml;

namespace FpmlSerializedCSharp
{
    public class CashSettlementPaymentDate : ISerialized
    {
        public CashSettlementPaymentDate(XmlNode xmlNode)
        {
            XmlNode adjustableDatesNode = xmlNode.SelectSingleNode("adjustableDates");
            
            if (adjustableDatesNode != null)
            {
                if (adjustableDatesNode.Attributes["href"] != null || adjustableDatesNode.Attributes["id"] != null) 
                {
                    if (adjustableDatesNode.Attributes["id"] != null) 
                    {
                        adjustableDatesIDRef_ = adjustableDatesNode.Attributes["id"].Value;
                        AdjustableDates ob = new AdjustableDates(adjustableDatesNode);
                        IDManager.SetID(adjustableDatesIDRef_, ob);
                    }
                    else if (adjustableDatesNode.Attributes["href"] != null)
                    {
                        adjustableDatesIDRef_ = adjustableDatesNode.Attributes["href"].Value;
                    }
                    else
                    {
                        adjustableDates_ = new AdjustableDates(adjustableDatesNode);
                    }
                }
                else
                {
                    adjustableDates_ = new AdjustableDates(adjustableDatesNode);
                }
            }
            
        
            XmlNode relativeDateNode = xmlNode.SelectSingleNode("relativeDate");
            
            if (relativeDateNode != null)
            {
                if (relativeDateNode.Attributes["href"] != null || relativeDateNode.Attributes["id"] != null) 
                {
                    if (relativeDateNode.Attributes["id"] != null) 
                    {
                        relativeDateIDRef_ = relativeDateNode.Attributes["id"].Value;
                        RelativeDateOffset ob = new RelativeDateOffset(relativeDateNode);
                        IDManager.SetID(relativeDateIDRef_, ob);
                    }
                    else if (relativeDateNode.Attributes["href"] != null)
                    {
                        relativeDateIDRef_ = relativeDateNode.Attributes["href"].Value;
                    }
                    else
                    {
                        relativeDate_ = new RelativeDateOffset(relativeDateNode);
                    }
                }
                else
                {
                    relativeDate_ = new RelativeDateOffset(relativeDateNode);
                }
            }
            
        
            XmlNode businessDateRangeNode = xmlNode.SelectSingleNode("businessDateRange");
            
            if (businessDateRangeNode != null)
            {
                if (businessDateRangeNode.Attributes["href"] != null || businessDateRangeNode.Attributes["id"] != null) 
                {
                    if (businessDateRangeNode.Attributes["id"] != null) 
                    {
                        businessDateRangeIDRef_ = businessDateRangeNode.Attributes["id"].Value;
                        BusinessDateRange ob = new BusinessDateRange(businessDateRangeNode);
                        IDManager.SetID(businessDateRangeIDRef_, ob);
                    }
                    else if (businessDateRangeNode.Attributes["href"] != null)
                    {
                        businessDateRangeIDRef_ = businessDateRangeNode.Attributes["href"].Value;
                    }
                    else
                    {
                        businessDateRange_ = new BusinessDateRange(businessDateRangeNode);
                    }
                }
                else
                {
                    businessDateRange_ = new BusinessDateRange(businessDateRangeNode);
                }
            }
            
        
        }
        
    
        #region AdjustableDates_
        private AdjustableDates adjustableDates_;
        public AdjustableDates AdjustableDates_
        {
            get
            {
                if (this.adjustableDates_ != null)
                {
                    return this.adjustableDates_; 
                }
                else if (this.adjustableDatesIDRef_ != null)
                {
                    adjustableDates_ = IDManager.getID(adjustableDatesIDRef_) as AdjustableDates;
                    return this.adjustableDates_; 
                }
                else
                {
                      return this.adjustableDates_; 
                }
            }
            set
            {
                if (this.adjustableDates_ != value)
                {
                    this.adjustableDates_ = value;
                }
            }
        }
        #endregion
        
        public string adjustableDatesIDRef_ { get; set; }
        #region RelativeDate_
        private RelativeDateOffset relativeDate_;
        public RelativeDateOffset RelativeDate_
        {
            get
            {
                if (this.relativeDate_ != null)
                {
                    return this.relativeDate_; 
                }
                else if (this.relativeDateIDRef_ != null)
                {
                    relativeDate_ = IDManager.getID(relativeDateIDRef_) as RelativeDateOffset;
                    return this.relativeDate_; 
                }
                else
                {
                      return this.relativeDate_; 
                }
            }
            set
            {
                if (this.relativeDate_ != value)
                {
                    this.relativeDate_ = value;
                }
            }
        }
        #endregion
        
        public string relativeDateIDRef_ { get; set; }
        #region BusinessDateRange_
        private BusinessDateRange businessDateRange_;
        public BusinessDateRange BusinessDateRange_
        {
            get
            {
                if (this.businessDateRange_ != null)
                {
                    return this.businessDateRange_; 
                }
                else if (this.businessDateRangeIDRef_ != null)
                {
                    businessDateRange_ = IDManager.getID(businessDateRangeIDRef_) as BusinessDateRange;
                    return this.businessDateRange_; 
                }
                else
                {
                      return this.businessDateRange_; 
                }
            }
            set
            {
                if (this.businessDateRange_ != value)
                {
                    this.businessDateRange_ = value;
                }
            }
        }
        #endregion
        
        public string businessDateRangeIDRef_ { get; set; }
        public string choiceStr_0;
        
    
        
    
    }
    
}
