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
    /// Excel_hifive_subtypeLoaderView.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Excel_hifive_subtypeLoaderView : UserControl
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

        public enum hifive_subtypeEnum
        {
            StepDown_Ki,
            StepDown_NoKi,
            StepUp_KI
        };

        // combo를 통해 선택되는 것들.
        #region SelectedViewModel_
        private Excel_hifive_subtypeViewModel selectedViewModel_;
        public Excel_hifive_subtypeViewModel SelectedViewModel_
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

        public Excel_hifive_subtypeLoaderView()
        {
            InitializeComponent();
            hifive_subtypeCombBox_.ItemsSource = Enum.GetValues(typeof(hifive_subtypeEnum));
        }

        private void ComboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            // 
            //Enum으로 박 ComboBoxItem item = this.hifive_subtypeCombBox_.SelectedItem as ComboBoxItem;
            hifive_subtypeEnum? item = this.hifive_subtypeCombBox_.SelectedItem as hifive_subtypeEnum?;
            string underType = item.ToString();
            //string underType = item.Content.ToString();

            if (underType.ToUpper() == "STEPDOWN_KI")
            {
                this.SelectedViewModel_ = new Excel_hifive_stepDown_kiViewModel();
            }
            else if (underType.ToUpper() == "STEPDOWN_NOKI")
            {
                this.SelectedViewModel_ = new Excel_hifive_stepDown_nokiViewModel();
            }
            else if (underType.ToUpper() == "STEPUP_KI")
            {
                this.SelectedViewModel_ = new Excel_hifive_stepUp_nokiViewModel();
            }
            else
            {
                OutputLogViewModel.addResult("no exist underType : " + underType);
            }

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
            if (type.ToUpper() == "EXCEL_HIFIVE_STEPDOWN_KI")
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

        public void initialize(Excel_hifive_subtypeViewModel e_hsvm)
        {
            this.hifive_subtypeCombBox_.SelectedIndex = this.comboBoxNum(e_hsvm.Excel_Type_);
            this.hifive_subtypeCombBox_.SelectionChanged += new SelectionChangedEventHandler(ComboBox_SelectionChanged);
            
            //view는 loaderView에서 적용했음. // 이건 submit했을때 적용할거 저장함.
            this.selectedViewModel_ = e_hsvm;
        }
    }
}
