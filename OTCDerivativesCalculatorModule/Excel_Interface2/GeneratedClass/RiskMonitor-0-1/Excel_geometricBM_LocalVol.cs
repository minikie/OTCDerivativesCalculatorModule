using System;
using System.Text;
using System.Collections.Generic;
using System.Xml;

namespace FpmlSerializedCSharp
{
    public class Excel_geometricBM_LocalVol : ISerialized
    {
        public Excel_geometricBM_LocalVol() { }
        public Excel_geometricBM_LocalVol(XmlNode xmlNode)
        : base(xmlNode)
        {
            XmlNode currentValueNode = xmlNode.SelectSingleNode("currentValue");
            
            if (currentValueNode != null)
            {
                if (currentValueNode.Attributes["href"] != null || currentValueNode.Attributes["id"] != null) 
                {
                    if (currentValueNode.Attributes["id"] != null) 
                    {
                        currentValueIDRef_ = currentValueNode.Attributes["id"].Value;
                        XsdTypeToken ob = new XsdTypeToken(currentValueNode);
                        IDManager.SetID(currentValueIDRef_, ob);
                    }
                    else if (currentValueNode.Attributes["href"] != null)
                    {
                        currentValueIDRef_ = currentValueNode.Attributes["href"].Value;
                    }
                    else
                    {
                        currentValue_ = new XsdTypeToken(currentValueNode);
                    }
                }
                else
                {
                    currentValue_ = new XsdTypeToken(currentValueNode);
                }
            }
            
        
            XmlNode driftNode = xmlNode.SelectSingleNode("drift");
            
            if (driftNode != null)
            {
                if (driftNode.Attributes["href"] != null || driftNode.Attributes["id"] != null) 
                {
                    if (driftNode.Attributes["id"] != null) 
                    {
                        driftIDRef_ = driftNode.Attributes["id"].Value;
                        XsdTypeToken ob = new XsdTypeToken(driftNode);
                        IDManager.SetID(driftIDRef_, ob);
                    }
                    else if (driftNode.Attributes["href"] != null)
                    {
                        driftIDRef_ = driftNode.Attributes["href"].Value;
                    }
                    else
                    {
                        drift_ = new XsdTypeToken(driftNode);
                    }
                }
                else
                {
                    drift_ = new XsdTypeToken(driftNode);
                }
            }
            
        
            XmlNode dividendNode = xmlNode.SelectSingleNode("dividend");
            
            if (dividendNode != null)
            {
                if (dividendNode.Attributes["href"] != null || dividendNode.Attributes["id"] != null) 
                {
                    if (dividendNode.Attributes["id"] != null) 
                    {
                        dividendIDRef_ = dividendNode.Attributes["id"].Value;
                        XsdTypeToken ob = new XsdTypeToken(dividendNode);
                        IDManager.SetID(dividendIDRef_, ob);
                    }
                    else if (dividendNode.Attributes["href"] != null)
                    {
                        dividendIDRef_ = dividendNode.Attributes["href"].Value;
                    }
                    else
                    {
                        dividend_ = new XsdTypeToken(dividendNode);
                    }
                }
                else
                {
                    dividend_ = new XsdTypeToken(dividendNode);
                }
            }
            
        
            XmlNode linkedSurfaceCodeNode = xmlNode.SelectSingleNode("linkedSurfaceCode");
            
            if (linkedSurfaceCodeNode != null)
            {
                if (linkedSurfaceCodeNode.Attributes["href"] != null || linkedSurfaceCodeNode.Attributes["id"] != null) 
                {
                    if (linkedSurfaceCodeNode.Attributes["id"] != null) 
                    {
                        linkedSurfaceCodeIDRef_ = linkedSurfaceCodeNode.Attributes["id"].Value;
                        XsdTypeToken ob = new XsdTypeToken(linkedSurfaceCodeNode);
                        IDManager.SetID(linkedSurfaceCodeIDRef_, ob);
                    }
                    else if (linkedSurfaceCodeNode.Attributes["href"] != null)
                    {
                        linkedSurfaceCodeIDRef_ = linkedSurfaceCodeNode.Attributes["href"].Value;
                    }
                    else
                    {
                        linkedSurfaceCode_ = new XsdTypeToken(linkedSurfaceCodeNode);
                    }
                }
                else
                {
                    linkedSurfaceCode_ = new XsdTypeToken(linkedSurfaceCodeNode);
                }
            }
            
        
            XmlNode excel_volSurfaceNode = xmlNode.SelectSingleNode("excel_volSurface");
            
            if (excel_volSurfaceNode != null)
            {
                if (excel_volSurfaceNode.Attributes["href"] != null || excel_volSurfaceNode.Attributes["id"] != null) 
                {
                    if (excel_volSurfaceNode.Attributes["id"] != null) 
                    {
                        excel_volSurfaceIDRef_ = excel_volSurfaceNode.Attributes["id"].Value;
                        Excel_volSurface ob = new Excel_volSurface(excel_volSurfaceNode);
                        IDManager.SetID(excel_volSurfaceIDRef_, ob);
                    }
                    else if (excel_volSurfaceNode.Attributes["href"] != null)
                    {
                        excel_volSurfaceIDRef_ = excel_volSurfaceNode.Attributes["href"].Value;
                    }
                    else
                    {
                        excel_volSurface_ = new Excel_volSurface(excel_volSurfaceNode);
                    }
                }
                else
                {
                    excel_volSurface_ = new Excel_volSurface(excel_volSurfaceNode);
                }
            }
            
        
            XmlNode vba_descriptionNode = xmlNode.SelectSingleNode("vba_description");
            
            if (vba_descriptionNode != null)
            {
                if (vba_descriptionNode.Attributes["href"] != null || vba_descriptionNode.Attributes["id"] != null) 
                {
                    if (vba_descriptionNode.Attributes["id"] != null) 
                    {
                        vba_descriptionIDRef_ = vba_descriptionNode.Attributes["id"].Value;
                        XsdTypeToken ob = new XsdTypeToken(vba_descriptionNode);
                        IDManager.SetID(vba_descriptionIDRef_, ob);
                    }
                    else if (vba_descriptionNode.Attributes["href"] != null)
                    {
                        vba_descriptionIDRef_ = vba_descriptionNode.Attributes["href"].Value;
                    }
                    else
                    {
                        vba_description_ = new XsdTypeToken(vba_descriptionNode);
                    }
                }
                else
                {
                    vba_description_ = new XsdTypeToken(vba_descriptionNode);
                }
            }
            
        
        }
        
    
        #region CurrentValue_
        private XsdTypeToken currentValue_;
        public XsdTypeToken CurrentValue_
        {
            get
            {
                if (this.currentValue_ != null)
                {
                    return this.currentValue_; 
                }
                else if (this.currentValueIDRef_ != null)
                {
                    currentValue_ = IDManager.getID(currentValueIDRef_) as XsdTypeToken;
                    return this.currentValue_; 
                }
                else
                {
                    throw new Exception( "currentValue_Node no exist!");
                }
            }
            set
            {
                if (this.currentValue_ != value)
                {
                    this.currentValue_ = value;
                }
            }
        }
        #endregion
        
        public string currentValueIDRef_ { get; set; }
        #region Drift_
        private XsdTypeToken drift_;
        public XsdTypeToken Drift_
        {
            get
            {
                if (this.drift_ != null)
                {
                    return this.drift_; 
                }
                else if (this.driftIDRef_ != null)
                {
                    drift_ = IDManager.getID(driftIDRef_) as XsdTypeToken;
                    return this.drift_; 
                }
                else
                {
                    throw new Exception( "drift_Node no exist!");
                }
            }
            set
            {
                if (this.drift_ != value)
                {
                    this.drift_ = value;
                }
            }
        }
        #endregion
        
        public string driftIDRef_ { get; set; }
        #region Dividend_
        private XsdTypeToken dividend_;
        public XsdTypeToken Dividend_
        {
            get
            {
                if (this.dividend_ != null)
                {
                    return this.dividend_; 
                }
                else if (this.dividendIDRef_ != null)
                {
                    dividend_ = IDManager.getID(dividendIDRef_) as XsdTypeToken;
                    return this.dividend_; 
                }
                else
                {
                    throw new Exception( "dividend_Node no exist!");
                }
            }
            set
            {
                if (this.dividend_ != value)
                {
                    this.dividend_ = value;
                }
            }
        }
        #endregion
        
        public string dividendIDRef_ { get; set; }
        #region LinkedSurfaceCode_
        private XsdTypeToken linkedSurfaceCode_;
        public XsdTypeToken LinkedSurfaceCode_
        {
            get
            {
                if (this.linkedSurfaceCode_ != null)
                {
                    return this.linkedSurfaceCode_; 
                }
                else if (this.linkedSurfaceCodeIDRef_ != null)
                {
                    linkedSurfaceCode_ = IDManager.getID(linkedSurfaceCodeIDRef_) as XsdTypeToken;
                    return this.linkedSurfaceCode_; 
                }
                else
                {
                    throw new Exception( "linkedSurfaceCode_Node no exist!");
                }
            }
            set
            {
                if (this.linkedSurfaceCode_ != value)
                {
                    this.linkedSurfaceCode_ = value;
                }
            }
        }
        #endregion
        
        public string linkedSurfaceCodeIDRef_ { get; set; }
        #region Excel_volSurface_
        private Excel_volSurface excel_volSurface_;
        public Excel_volSurface Excel_volSurface_
        {
            get
            {
                if (this.excel_volSurface_ != null)
                {
                    return this.excel_volSurface_; 
                }
                else if (this.excel_volSurfaceIDRef_ != null)
                {
                    excel_volSurface_ = IDManager.getID(excel_volSurfaceIDRef_) as Excel_volSurface;
                    return this.excel_volSurface_; 
                }
                else
                {
                    throw new Exception( "excel_volSurface_Node no exist!");
                }
            }
            set
            {
                if (this.excel_volSurface_ != value)
                {
                    this.excel_volSurface_ = value;
                }
            }
        }
        #endregion
        
        public string excel_volSurfaceIDRef_ { get; set; }
        #region Vba_description_
        private XsdTypeToken vba_description_;
        public XsdTypeToken Vba_description_
        {
            get
            {
                if (this.vba_description_ != null)
                {
                    return this.vba_description_; 
                }
                else if (this.vba_descriptionIDRef_ != null)
                {
                    vba_description_ = IDManager.getID(vba_descriptionIDRef_) as XsdTypeToken;
                    return this.vba_description_; 
                }
                else
                {
                    throw new Exception( "vba_description_Node no exist!");
                }
            }
            set
            {
                if (this.vba_description_ != value)
                {
                    this.vba_description_ = value;
                }
            }
        }
        #endregion
        
        public string vba_descriptionIDRef_ { get; set; }
        
    
        
    
    }
    
}
