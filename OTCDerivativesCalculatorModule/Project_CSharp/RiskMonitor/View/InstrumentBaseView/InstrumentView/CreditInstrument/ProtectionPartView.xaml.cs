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

namespace RiskMonitor
{
    /// <summary>
    /// ProtectionPartView.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class ProtectionPartView : UserControl
    {
        #region ViewModel_
        private ProtectionPartViewModel viewModel_;
        public ProtectionPartViewModel ViewModel_
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

        public ProtectionPartView()
        {
            InitializeComponent();
            this.DataContextChanged += new DependencyPropertyChangedEventHandler(ViewModelChanged);
        }

        private void ViewModelChanged(object sender, DependencyPropertyChangedEventArgs e)
        {
            
            //this.viewModel_ = this.DataContext as ReferenceInformationListViewModel;
            //this.referenceInfoListDataGrid_.ItemsSource = this.viewModel_.ReferenceInformationViewModel_;
        }
    }
}
