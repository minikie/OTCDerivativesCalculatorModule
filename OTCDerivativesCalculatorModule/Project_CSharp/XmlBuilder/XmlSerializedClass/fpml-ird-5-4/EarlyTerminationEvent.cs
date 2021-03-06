using System;
using System.Text;
using System.Collections.Generic;
using System.Xml;

namespace FpmlSerializedCSharp
{
    public class EarlyTerminationEvent : ISerialized
    {
        public EarlyTerminationEvent(XmlNode xmlNode)
        {
            XmlNode adjustedExerciseDateNode = xmlNode.SelectSingleNode("adjustedExerciseDate");
            
            if (adjustedExerciseDateNode != null)
            {
                if (adjustedExerciseDateNode.Attributes["href"] != null || adjustedExerciseDateNode.Attributes["id"] != null) 
                {
                    if (adjustedExerciseDateNode.Attributes["id"] != null) 
                    {
                        adjustedExerciseDateIDRef_ = adjustedExerciseDateNode.Attributes["id"].Value;
                        XsdTypeDate ob = new XsdTypeDate(adjustedExerciseDateNode);
                        IDManager.SetID(adjustedExerciseDateIDRef_, ob);
                    }
                    else if (adjustedExerciseDateNode.Attributes["href"] != null)
                    {
                        adjustedExerciseDateIDRef_ = adjustedExerciseDateNode.Attributes["href"].Value;
                    }
                    else
                    {
                        adjustedExerciseDate_ = new XsdTypeDate(adjustedExerciseDateNode);
                    }
                }
                else
                {
                    adjustedExerciseDate_ = new XsdTypeDate(adjustedExerciseDateNode);
                }
            }
            
        
            XmlNode adjustedEarlyTerminationDateNode = xmlNode.SelectSingleNode("adjustedEarlyTerminationDate");
            
            if (adjustedEarlyTerminationDateNode != null)
            {
                if (adjustedEarlyTerminationDateNode.Attributes["href"] != null || adjustedEarlyTerminationDateNode.Attributes["id"] != null) 
                {
                    if (adjustedEarlyTerminationDateNode.Attributes["id"] != null) 
                    {
                        adjustedEarlyTerminationDateIDRef_ = adjustedEarlyTerminationDateNode.Attributes["id"].Value;
                        XsdTypeDate ob = new XsdTypeDate(adjustedEarlyTerminationDateNode);
                        IDManager.SetID(adjustedEarlyTerminationDateIDRef_, ob);
                    }
                    else if (adjustedEarlyTerminationDateNode.Attributes["href"] != null)
                    {
                        adjustedEarlyTerminationDateIDRef_ = adjustedEarlyTerminationDateNode.Attributes["href"].Value;
                    }
                    else
                    {
                        adjustedEarlyTerminationDate_ = new XsdTypeDate(adjustedEarlyTerminationDateNode);
                    }
                }
                else
                {
                    adjustedEarlyTerminationDate_ = new XsdTypeDate(adjustedEarlyTerminationDateNode);
                }
            }
            
        
            XmlNode adjustedCashSettlementValuationDateNode = xmlNode.SelectSingleNode("adjustedCashSettlementValuationDate");
            
            if (adjustedCashSettlementValuationDateNode != null)
            {
                if (adjustedCashSettlementValuationDateNode.Attributes["href"] != null || adjustedCashSettlementValuationDateNode.Attributes["id"] != null) 
                {
                    if (adjustedCashSettlementValuationDateNode.Attributes["id"] != null) 
                    {
                        adjustedCashSettlementValuationDateIDRef_ = adjustedCashSettlementValuationDateNode.Attributes["id"].Value;
                        XsdTypeDate ob = new XsdTypeDate(adjustedCashSettlementValuationDateNode);
                        IDManager.SetID(adjustedCashSettlementValuationDateIDRef_, ob);
                    }
                    else if (adjustedCashSettlementValuationDateNode.Attributes["href"] != null)
                    {
                        adjustedCashSettlementValuationDateIDRef_ = adjustedCashSettlementValuationDateNode.Attributes["href"].Value;
                    }
                    else
                    {
                        adjustedCashSettlementValuationDate_ = new XsdTypeDate(adjustedCashSettlementValuationDateNode);
                    }
                }
                else
                {
                    adjustedCashSettlementValuationDate_ = new XsdTypeDate(adjustedCashSettlementValuationDateNode);
                }
            }
            
        
            XmlNode adjustedCashSettlementPaymentDateNode = xmlNode.SelectSingleNode("adjustedCashSettlementPaymentDate");
            
            if (adjustedCashSettlementPaymentDateNode != null)
            {
                if (adjustedCashSettlementPaymentDateNode.Attributes["href"] != null || adjustedCashSettlementPaymentDateNode.Attributes["id"] != null) 
                {
                    if (adjustedCashSettlementPaymentDateNode.Attributes["id"] != null) 
                    {
                        adjustedCashSettlementPaymentDateIDRef_ = adjustedCashSettlementPaymentDateNode.Attributes["id"].Value;
                        XsdTypeDate ob = new XsdTypeDate(adjustedCashSettlementPaymentDateNode);
                        IDManager.SetID(adjustedCashSettlementPaymentDateIDRef_, ob);
                    }
                    else if (adjustedCashSettlementPaymentDateNode.Attributes["href"] != null)
                    {
                        adjustedCashSettlementPaymentDateIDRef_ = adjustedCashSettlementPaymentDateNode.Attributes["href"].Value;
                    }
                    else
                    {
                        adjustedCashSettlementPaymentDate_ = new XsdTypeDate(adjustedCashSettlementPaymentDateNode);
                    }
                }
                else
                {
                    adjustedCashSettlementPaymentDate_ = new XsdTypeDate(adjustedCashSettlementPaymentDateNode);
                }
            }
            
        
            XmlNode adjustedExerciseFeePaymentDateNode = xmlNode.SelectSingleNode("adjustedExerciseFeePaymentDate");
            
            if (adjustedExerciseFeePaymentDateNode != null)
            {
                if (adjustedExerciseFeePaymentDateNode.Attributes["href"] != null || adjustedExerciseFeePaymentDateNode.Attributes["id"] != null) 
                {
                    if (adjustedExerciseFeePaymentDateNode.Attributes["id"] != null) 
                    {
                        adjustedExerciseFeePaymentDateIDRef_ = adjustedExerciseFeePaymentDateNode.Attributes["id"].Value;
                        XsdTypeDate ob = new XsdTypeDate(adjustedExerciseFeePaymentDateNode);
                        IDManager.SetID(adjustedExerciseFeePaymentDateIDRef_, ob);
                    }
                    else if (adjustedExerciseFeePaymentDateNode.Attributes["href"] != null)
                    {
                        adjustedExerciseFeePaymentDateIDRef_ = adjustedExerciseFeePaymentDateNode.Attributes["href"].Value;
                    }
                    else
                    {
                        adjustedExerciseFeePaymentDate_ = new XsdTypeDate(adjustedExerciseFeePaymentDateNode);
                    }
                }
                else
                {
                    adjustedExerciseFeePaymentDate_ = new XsdTypeDate(adjustedExerciseFeePaymentDateNode);
                }
            }
            
        
        }
        
    
        #region AdjustedExerciseDate_
        private XsdTypeDate adjustedExerciseDate_;
        public XsdTypeDate AdjustedExerciseDate_
        {
            get
            {
                if (this.adjustedExerciseDate_ != null)
                {
                    return this.adjustedExerciseDate_; 
                }
                else if (this.adjustedExerciseDateIDRef_ != null)
                {
                    adjustedExerciseDate_ = IDManager.getID(adjustedExerciseDateIDRef_) as XsdTypeDate;
                    return this.adjustedExerciseDate_; 
                }
                else
                {
                      return this.adjustedExerciseDate_; 
                }
            }
            set
            {
                if (this.adjustedExerciseDate_ != value)
                {
                    this.adjustedExerciseDate_ = value;
                }
            }
        }
        #endregion
        
        public string adjustedExerciseDateIDRef_ { get; set; }
        #region AdjustedEarlyTerminationDate_
        private XsdTypeDate adjustedEarlyTerminationDate_;
        public XsdTypeDate AdjustedEarlyTerminationDate_
        {
            get
            {
                if (this.adjustedEarlyTerminationDate_ != null)
                {
                    return this.adjustedEarlyTerminationDate_; 
                }
                else if (this.adjustedEarlyTerminationDateIDRef_ != null)
                {
                    adjustedEarlyTerminationDate_ = IDManager.getID(adjustedEarlyTerminationDateIDRef_) as XsdTypeDate;
                    return this.adjustedEarlyTerminationDate_; 
                }
                else
                {
                      return this.adjustedEarlyTerminationDate_; 
                }
            }
            set
            {
                if (this.adjustedEarlyTerminationDate_ != value)
                {
                    this.adjustedEarlyTerminationDate_ = value;
                }
            }
        }
        #endregion
        
        public string adjustedEarlyTerminationDateIDRef_ { get; set; }
        #region AdjustedCashSettlementValuationDate_
        private XsdTypeDate adjustedCashSettlementValuationDate_;
        public XsdTypeDate AdjustedCashSettlementValuationDate_
        {
            get
            {
                if (this.adjustedCashSettlementValuationDate_ != null)
                {
                    return this.adjustedCashSettlementValuationDate_; 
                }
                else if (this.adjustedCashSettlementValuationDateIDRef_ != null)
                {
                    adjustedCashSettlementValuationDate_ = IDManager.getID(adjustedCashSettlementValuationDateIDRef_) as XsdTypeDate;
                    return this.adjustedCashSettlementValuationDate_; 
                }
                else
                {
                      return this.adjustedCashSettlementValuationDate_; 
                }
            }
            set
            {
                if (this.adjustedCashSettlementValuationDate_ != value)
                {
                    this.adjustedCashSettlementValuationDate_ = value;
                }
            }
        }
        #endregion
        
        public string adjustedCashSettlementValuationDateIDRef_ { get; set; }
        #region AdjustedCashSettlementPaymentDate_
        private XsdTypeDate adjustedCashSettlementPaymentDate_;
        public XsdTypeDate AdjustedCashSettlementPaymentDate_
        {
            get
            {
                if (this.adjustedCashSettlementPaymentDate_ != null)
                {
                    return this.adjustedCashSettlementPaymentDate_; 
                }
                else if (this.adjustedCashSettlementPaymentDateIDRef_ != null)
                {
                    adjustedCashSettlementPaymentDate_ = IDManager.getID(adjustedCashSettlementPaymentDateIDRef_) as XsdTypeDate;
                    return this.adjustedCashSettlementPaymentDate_; 
                }
                else
                {
                      return this.adjustedCashSettlementPaymentDate_; 
                }
            }
            set
            {
                if (this.adjustedCashSettlementPaymentDate_ != value)
                {
                    this.adjustedCashSettlementPaymentDate_ = value;
                }
            }
        }
        #endregion
        
        public string adjustedCashSettlementPaymentDateIDRef_ { get; set; }
        #region AdjustedExerciseFeePaymentDate_
        private XsdTypeDate adjustedExerciseFeePaymentDate_;
        public XsdTypeDate AdjustedExerciseFeePaymentDate_
        {
            get
            {
                if (this.adjustedExerciseFeePaymentDate_ != null)
                {
                    return this.adjustedExerciseFeePaymentDate_; 
                }
                else if (this.adjustedExerciseFeePaymentDateIDRef_ != null)
                {
                    adjustedExerciseFeePaymentDate_ = IDManager.getID(adjustedExerciseFeePaymentDateIDRef_) as XsdTypeDate;
                    return this.adjustedExerciseFeePaymentDate_; 
                }
                else
                {
                      return this.adjustedExerciseFeePaymentDate_; 
                }
            }
            set
            {
                if (this.adjustedExerciseFeePaymentDate_ != value)
                {
                    this.adjustedExerciseFeePaymentDate_ = value;
                }
            }
        }
        #endregion
        
        public string adjustedExerciseFeePaymentDateIDRef_ { get; set; }
        
    
        
    
    }
    
}

