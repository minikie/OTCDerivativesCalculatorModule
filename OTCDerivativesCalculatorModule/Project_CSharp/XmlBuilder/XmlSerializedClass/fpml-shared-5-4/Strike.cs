using System;
using System.Text;
using System.Collections.Generic;
using System.Xml;

namespace FpmlSerializedCSharp
{
    public class Strike : ISerialized
    {
        public Strike(XmlNode xmlNode)
        {
            XmlNode strikeRateNode = xmlNode.SelectSingleNode("strikeRate");
            
            if (strikeRateNode != null)
            {
                if (strikeRateNode.Attributes["href"] != null || strikeRateNode.Attributes["id"] != null) 
                {
                    if (strikeRateNode.Attributes["id"] != null) 
                    {
                        strikeRateIDRef_ = strikeRateNode.Attributes["id"].Value;
                        XsdTypeDecimal ob = new XsdTypeDecimal(strikeRateNode);
                        IDManager.SetID(strikeRateIDRef_, ob);
                    }
                    else if (strikeRateNode.Attributes["href"] != null)
                    {
                        strikeRateIDRef_ = strikeRateNode.Attributes["href"].Value;
                    }
                    else
                    {
                        strikeRate_ = new XsdTypeDecimal(strikeRateNode);
                    }
                }
                else
                {
                    strikeRate_ = new XsdTypeDecimal(strikeRateNode);
                }
            }
            
        
            XmlNode buyerNode = xmlNode.SelectSingleNode("buyer");
            
            if (buyerNode != null)
            {
                if (buyerNode.Attributes["href"] != null || buyerNode.Attributes["id"] != null) 
                {
                    if (buyerNode.Attributes["id"] != null) 
                    {
                        buyerIDRef_ = buyerNode.Attributes["id"].Value;
                        IdentifiedPayerReceiver ob = new IdentifiedPayerReceiver(buyerNode);
                        IDManager.SetID(buyerIDRef_, ob);
                    }
                    else if (buyerNode.Attributes["href"] != null)
                    {
                        buyerIDRef_ = buyerNode.Attributes["href"].Value;
                    }
                    else
                    {
                        buyer_ = new IdentifiedPayerReceiver(buyerNode);
                    }
                }
                else
                {
                    buyer_ = new IdentifiedPayerReceiver(buyerNode);
                }
            }
            
        
            XmlNode sellerNode = xmlNode.SelectSingleNode("seller");
            
            if (sellerNode != null)
            {
                if (sellerNode.Attributes["href"] != null || sellerNode.Attributes["id"] != null) 
                {
                    if (sellerNode.Attributes["id"] != null) 
                    {
                        sellerIDRef_ = sellerNode.Attributes["id"].Value;
                        IdentifiedPayerReceiver ob = new IdentifiedPayerReceiver(sellerNode);
                        IDManager.SetID(sellerIDRef_, ob);
                    }
                    else if (sellerNode.Attributes["href"] != null)
                    {
                        sellerIDRef_ = sellerNode.Attributes["href"].Value;
                    }
                    else
                    {
                        seller_ = new IdentifiedPayerReceiver(sellerNode);
                    }
                }
                else
                {
                    seller_ = new IdentifiedPayerReceiver(sellerNode);
                }
            }
            
        
        }
        
    
        #region StrikeRate_
        private XsdTypeDecimal strikeRate_;
        public XsdTypeDecimal StrikeRate_
        {
            get
            {
                if (this.strikeRate_ != null)
                {
                    return this.strikeRate_; 
                }
                else if (this.strikeRateIDRef_ != null)
                {
                    strikeRate_ = IDManager.getID(strikeRateIDRef_) as XsdTypeDecimal;
                    return this.strikeRate_; 
                }
                else
                {
                      return this.strikeRate_; 
                }
            }
            set
            {
                if (this.strikeRate_ != value)
                {
                    this.strikeRate_ = value;
                }
            }
        }
        #endregion
        
        public string strikeRateIDRef_ { get; set; }
        #region Buyer_
        private IdentifiedPayerReceiver buyer_;
        public IdentifiedPayerReceiver Buyer_
        {
            get
            {
                if (this.buyer_ != null)
                {
                    return this.buyer_; 
                }
                else if (this.buyerIDRef_ != null)
                {
                    buyer_ = IDManager.getID(buyerIDRef_) as IdentifiedPayerReceiver;
                    return this.buyer_; 
                }
                else
                {
                      return this.buyer_; 
                }
            }
            set
            {
                if (this.buyer_ != value)
                {
                    this.buyer_ = value;
                }
            }
        }
        #endregion
        
        public string buyerIDRef_ { get; set; }
        #region Seller_
        private IdentifiedPayerReceiver seller_;
        public IdentifiedPayerReceiver Seller_
        {
            get
            {
                if (this.seller_ != null)
                {
                    return this.seller_; 
                }
                else if (this.sellerIDRef_ != null)
                {
                    seller_ = IDManager.getID(sellerIDRef_) as IdentifiedPayerReceiver;
                    return this.seller_; 
                }
                else
                {
                      return this.seller_; 
                }
            }
            set
            {
                if (this.seller_ != value)
                {
                    this.seller_ = value;
                }
            }
        }
        #endregion
        
        public string sellerIDRef_ { get; set; }
        
    
        
    
    }
    
}

