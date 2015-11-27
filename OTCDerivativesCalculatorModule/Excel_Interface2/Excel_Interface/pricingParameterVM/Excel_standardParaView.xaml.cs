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
    /// Excel_standardParaView.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Excel_standardParaView : UserControl
    {
        #region ViewModel_
        private Excel_standardParaViewModel viewModel_;
        public Excel_standardParaViewModel ViewModel_
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

        public Excel_standardParaView()
        {
            InitializeComponent();
            this.DataContextChanged += new DependencyPropertyChangedEventHandler(ViewModelChanged);
        }

        private void ViewModelChanged(object sender, DependencyPropertyChangedEventArgs e)
        {
            this.viewModel_ = this.DataContext as Excel_standardParaViewModel;

            this.UnderlyingParaInfoGrid_.Children.Clear();
            this.UnderlyingParaInfoGrid_.Children.Add(this.viewModel_.Excel_underlyingCalcInfo_paraViewModel_.view());

            this.DiscountCurveInfoGrid_.Children.Clear();
            this.DiscountCurveInfoGrid_.Children.Add(this.viewModel_.Excel_discountCurve_paraViewModel_.view());
        }

    }
}
