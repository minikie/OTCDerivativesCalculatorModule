﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace RiskMonitor
{
    public class ELSStepDownTemplate : ContentsListViewModel
    {
        public ELSStepDownTemplate() 
        {

            this.InstrumentTemplateList_.Add(new TemplateStepDownWithKI());

        }
    }
}
