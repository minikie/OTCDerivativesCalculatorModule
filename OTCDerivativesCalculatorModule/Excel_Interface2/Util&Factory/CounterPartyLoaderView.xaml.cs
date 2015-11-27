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
    /// CounterPartyLoaderView.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class CounterPartyLoaderView : UserControl
    {
        #region SelectedCounterParty_
        private string selectedCounterParty_;
        public string SelectedCounterParty_
        {
            get { return this.selectedCounterParty_; }
            set
            {
                if (this.selectedCounterParty_ != value)
                {
                    this.selectedCounterParty_ = value;
                    //this.NotifyPropertyChanged("SelectedCounterParty_");
                }
            }
        }
        #endregion

        public CounterPartyLoaderView()
        {
            InitializeComponent();
        }

        private void SurmitButton_Click(object sender, RoutedEventArgs e)
        {
            ((Window)this.Parent).DialogResult = true;
            ((Window)this.Parent).Close();
        }

        private void CancelButton_Click(object sender, RoutedEventArgs e)
        {
            ((Window)this.Parent).DialogResult = false;
            ((Window)this.Parent).Close();
        }

    }
}
