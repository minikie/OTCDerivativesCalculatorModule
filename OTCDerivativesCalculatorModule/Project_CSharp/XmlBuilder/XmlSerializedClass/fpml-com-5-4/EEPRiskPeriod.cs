using System;
using System.Text;
using System.Collections.Generic;
using System.Xml;

namespace FpmlSerializedCSharp
{
    public class EEPRiskPeriod : ISerialized
    {
        public EEPRiskPeriod(XmlNode xmlNode)
        {
            XmlNode startDateNode = xmlNode.SelectSingleNode("startDate");
            
            if (startDateNode != null)
            {
                if (startDateNode.Attributes["href"] != null || startDateNode.Attributes["id"] != null) 
                {
                    if (startDateNode.Attributes["id"] != null) 
                    {
                        startDateIDRef_ = startDateNode.Attributes["id"].Value;
                        XsdTypeDate ob = new XsdTypeDate(startDateNode);
                        IDManager.SetID(startDateIDRef_, ob);
                    }
                    else if (startDateNode.Attributes["href"] != null)
                    {
                        startDateIDRef_ = startDateNode.Attributes["href"].Value;
                    }
                    else
                    {
                        startDate_ = new XsdTypeDate(startDateNode);
                    }
                }
                else
                {
                    startDate_ = new XsdTypeDate(startDateNode);
                }
            }
            
        
            XmlNode endDateNode = xmlNode.SelectSingleNode("endDate");
            
            if (endDateNode != null)
            {
                if (endDateNode.Attributes["href"] != null || endDateNode.Attributes["id"] != null) 
                {
                    if (endDateNode.Attributes["id"] != null) 
                    {
                        endDateIDRef_ = endDateNode.Attributes["id"].Value;
                        XsdTypeDate ob = new XsdTypeDate(endDateNode);
                        IDManager.SetID(endDateIDRef_, ob);
                    }
                    else if (endDateNode.Attributes["href"] != null)
                    {
                        endDateIDRef_ = endDateNode.Attributes["href"].Value;
                    }
                    else
                    {
                        endDate_ = new XsdTypeDate(endDateNode);
                    }
                }
                else
                {
                    endDate_ = new XsdTypeDate(endDateNode);
                }
            }
            
        
        }
        
    
        #region StartDate_
        private XsdTypeDate startDate_;
        public XsdTypeDate StartDate_
        {
            get
            {
                if (this.startDate_ != null)
                {
                    return this.startDate_; 
                }
                else if (this.startDateIDRef_ != null)
                {
                    startDate_ = IDManager.getID(startDateIDRef_) as XsdTypeDate;
                    return this.startDate_; 
                }
                else
                {
                      return this.startDate_; 
                }
            }
            set
            {
                if (this.startDate_ != value)
                {
                    this.startDate_ = value;
                }
            }
        }
        #endregion
        
        public string startDateIDRef_ { get; set; }
        #region EndDate_
        private XsdTypeDate endDate_;
        public XsdTypeDate EndDate_
        {
            get
            {
                if (this.endDate_ != null)
                {
                    return this.endDate_; 
                }
                else if (this.endDateIDRef_ != null)
                {
                    endDate_ = IDManager.getID(endDateIDRef_) as XsdTypeDate;
                    return this.endDate_; 
                }
                else
                {
                      return this.endDate_; 
                }
            }
            set
            {
                if (this.endDate_ != value)
                {
                    this.endDate_ = value;
                }
            }
        }
        #endregion
        
        public string endDateIDRef_ { get; set; }
        
    
        
    
    }
    
}
