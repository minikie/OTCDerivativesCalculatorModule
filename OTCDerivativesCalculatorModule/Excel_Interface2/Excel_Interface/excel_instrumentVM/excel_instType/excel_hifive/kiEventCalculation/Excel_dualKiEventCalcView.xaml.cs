﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Excel_Interface
{
    /// <summary>
    /// Excel_dualKiEventCalcView.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Excel_dualKiEventCalcView : UserControl
    {
        #region ViewModel_
        private Excel_dualKiEventCalcViewModel viewModel_;
        public Excel_dualKiEventCalcViewModel ViewModel_
        {
            get { return this.viewModel_; }
            set
            {
                if (this.viewModel_ != value)
                {
                    this.viewModel_ = value;
                    //this.NotifyPropertyChanged("ViewModel_");
                }
            }
        }
        #endregion

        public Excel_dualKiEventCalcView()
        {
            InitializeComponent();
        }
    }
}
