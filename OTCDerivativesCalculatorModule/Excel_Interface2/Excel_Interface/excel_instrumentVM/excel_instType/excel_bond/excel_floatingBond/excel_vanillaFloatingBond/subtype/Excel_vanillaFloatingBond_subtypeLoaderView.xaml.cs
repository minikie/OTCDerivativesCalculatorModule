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
using System.ComponentModel;
using System.Collections.ObjectModel;

namespace Excel_Interface
{
    /// <summary>
    /// Excel_vanillaFloatingBond_subtypeLoaderView.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Excel_vanillaFloatingBond_subtypeLoaderView : UserControl
    {
        #region Event
        public event PropertyChangedEventHandler PropertyChanged;

        protected void NotifyPropertyChanged(string propertyName)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
            }
        }
        #endregion

        public enum vanillaFloatingBond_subtypeEnum
        {
            Simple
        };

        // combo를 통해 선택되는 것들.
        #region SelectedViewModel_
        private Excel_vanillaFloatingBond_subtypeViewModel selectedViewModel_;
        public Excel_vanillaFloatingBond_subtypeViewModel SelectedViewModel_
        {
            get { return this.selectedViewModel_; }
            set
            {
                if (this.selectedViewModel_ != value)
                {
                    this.selectedViewModel_ = value;

                    this.selectedSubtypeGrid_.Children.Clear();
                    this.selectedSubtypeGrid_.Children.Add(this.selectedViewModel_.view());

                    //this.NotifyPropertyChanged("SelectedViewModel_");
                }
            }
        }
        #endregion

        #region Excel_underlyingCalcInfoViewModel_
        private Excel_underlyingCalcInfoViewModel excel_underlyingCalcInfoViewModel_;
        public Excel_underlyingCalcInfoViewModel Excel_underlyingCalcInfoViewModel_
        {
            get { return this.excel_underlyingCalcInfoViewModel_; }
            set
            {
                if (this.excel_underlyingCalcInfoViewModel_ != value)
                {
                    this.excel_underlyingCalcInfoViewModel_ = value;
                    this.NotifyPropertyChanged("Excel_underlyingCalcInfoViewModel_");
                }
            }
        }

        #endregion

        public Excel_vanillaFloatingBond_subtypeLoaderView()
        {
            InitializeComponent();

            vanillaFloatingBond_subtypeCombBox_.ItemsSource = Enum.GetValues(typeof(vanillaFloatingBond_subtypeEnum));
        }

        //    this.DataContextChanged += new DependencyPropertyChangedEventHandler(ViewModelChanged);
        //}

        //private void ViewModelChanged(object sender, DependencyPropertyChangedEventArgs e)
        //{
        //    this.viewModel_ = this.DataContext as Excel_scheduleListViewModel;
        //    this.ScheduleDataGrid_.ItemsSource = this.viewModel_.Excel_scheduleViewModel_;
        //}

        private void ComboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            ComboBoxItem item = this.vanillaFloatingBond_subtypeCombBox_.SelectedItem as ComboBoxItem;
            string underType = item.Content.ToString();

            if (underType.ToUpper() == "SIMPLE")
            {
                this.SelectedViewModel_ = new Excel_vanillaFloatingBond_simpleViewModel();
            }
            //else if (underType.ToUpper() == "STEPDOWN_NOKI")
            //{
            //    this.SelectedViewModel_ = new Excel_hifive_stepDown_nokiViewModel();
            //}
            //else if (underType.ToUpper() == "STEPUP_KI")
            //{
            //    this.SelectedViewModel_ = new Excel_hifive_stepUp_nokiViewModel();
            //}
            else
            {
                OutputLogViewModel.addResult("no exist underType : " + underType);
            }

            //// 이거 위로 prop 안으로 집어넣어야하나..?  ㅇㅇ 집어 넣었음
            this.selectedViewModel_.setUnderlying(this.excel_underlyingCalcInfoViewModel_);

            this.selectedSubtypeGrid_.Children.Clear();
            this.selectedSubtypeGrid_.Children.Add(this.SelectedViewModel_.view());
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

        private int comboBoxNum(string type)
        {
            if (type.ToUpper() == "EXCEL_VANILLAFLOATINGBOND_SIMPLE")
            {
                return 0;
            }
            //else if (type.ToUpper() == "EXCEL_VANILLARETURNCAL")
            //{
            //    return 1;
            //}
            else
            {
                // 못찾아서 미선택함
                return -1;
            }
        }

        public void initialize(Excel_vanillaFloatingBond_subtypeViewModel e_vfbsvm)
        {
            this.vanillaFloatingBond_subtypeCombBox_.SelectedIndex = this.comboBoxNum(e_vfbsvm.Excel_type_);
            this.vanillaFloatingBond_subtypeCombBox_.SelectionChanged += new SelectionChangedEventHandler(ComboBox_SelectionChanged);

            //view는 loaderView에서 적용했음. // 이건 submit했을때 적용할거 저장함.
            this.selectedViewModel_ = e_vfbsvm;
        }
    }
}
