using System;
using System.Text;
using System.Xml;
using CSharpCodeGen;

namespace FpmlSerializedCSharp
{
    public class SpecifiedCurrency
    {
        public SpecifiedCurrency(XmlNode xmlNode)
        {
            XmlNodeList applicableNodeList = xmlNode.SelectNodes("applicable");
            if (applicableNodeList.Count > 1 )
            {
                    throw new Exception();
            }
            
            foreach (XmlNode item in applicableNodeList)
            {
                if (item.Attributes["href"] != null || item.Attributes["id"] == null) 
                {
                    if (item.Attributes["id"] != null) 
                    {
                        applicableIDRef = item.Attributes["id"].Name;
                        XsdTypeBoolean ob = XsdTypeBoolean();
                        IDManager.SetID(applicableIDRef, ob);
                    }
                    else if (item.Attributes.ToString() == "href")
                    {
                        applicableIDRef = item.Attributes["href"].Name;
                    }
                    else
                    {
                        applicable = new XsdTypeBoolean(item);
                    }
                }
            }
            
        
            XmlNodeList currencyNodeList = xmlNode.SelectNodes("currency");
            
            foreach (XmlNode item in currencyNodeList)
            {
                if (item.Attributes["href"] != null || item.Attributes["id"] == null) 
                {
                    if (item.Attributes["id"] != null) 
                    {
                        currencyIDRef = item.Attributes["id"].Name;
                        List<Currency> ob = new List<Currency>();
                        ob.Add(new Currency(item));
                        IDManager.SetID(currencyIDRef, ob);
                    }
                    else if (item.Attributes.ToString() == "href")
                    {
                        currencyIDRef = item.Attributes["href"].Name;
                    }
                    else
                    {
                    currency.Add(new Currency(item));
                    }
                }
            }
            
        
        }
        
    
        #region Applicable
        private XsdTypeBoolean applicable;
        public XsdTypeBoolean Applicable
        {
            get
            {
                if (this.applicable != null)
                {
                    return this.applicable; 
                }
                else if (this.applicableIDRef != null)
                {
                    applicable = IDManager.getID(applicableIDRef) as XsdTypeBoolean;
                    return this.applicable; 
                }
                else
                {
                    throw new NotImplementedException();
                }
            }
            set
            {
                if (this.applicable != value)
                {
                    this.applicable = value;
                }
            }
        }
        #endregion
        
        public string XsdTypeBooleanIDRef { get; set; }
        #region Currency
        private List<Currency> currency;
        public List<Currency> Currency
        {
            get
            {
                if (this.currency != null)
                {
                    return this.currency; 
                }
                else if (this.currencyIDRef != null)
                {
                    currency = IDManager.getID(currencyIDRef) as List<Currency>;
                    return this.currency; 
                }
                else
                {
                    throw new NotImplementedException();
                }
            }
            set
            {
                if (this.currency != value)
                {
                    this.currency = value;
                }
            }
        }
        #endregion
        
        public string CurrencyIDRef { get; set; }
        
    
        
    
    }
    
}
