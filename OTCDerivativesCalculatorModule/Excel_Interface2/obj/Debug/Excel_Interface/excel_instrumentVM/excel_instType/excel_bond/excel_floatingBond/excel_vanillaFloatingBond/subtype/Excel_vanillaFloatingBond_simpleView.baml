   M S B A M L   `   `   `  ����  Excel_Interface2:    4Excel_Interface.Excel_vanillaFloatingBond_simpleView   5      \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5      R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5      Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5      @d2http://schemas.microsoft.com/expression/blend/2008     5      .��5      � .+�5   
   ��   �� Orientation$  Vertical=�6   .+�5	      �� $  
Horizontal=�6   .+�5
      �� $��Product String :��6   �� 5      $	��150��6   ��6&   ��  �� Path$ ProductString_��� 5      $��40��6   $��Valid��6%   $��Center=�62   $��Center=�6T   �� 5      -   5        $��30��5      $	��set��6$   62   5      �� 5      $  
Horizontal=�6   .+�5      �� $  Vertical=�6   .+�5      �� $  
Horizontal=�6!   .+�5      �� $��	Gearing :��6    �� 5      $��60��6"   ��6-   �� $ Gearing_�5      �� 5      $  
Horizontal=�6!   .+�5      �� $��Spread :��6    �� 5      $��60��6"   ��6-   �� $ Spread_��� 5      $��bp��6    5      � 5      -   5        $��scheduleGenGrid_��5      5      &   System.Windows.Controls.DataGrid  5      -   5        $��subScheduleDataGrid_��5         AutoGenerateColumns .  ��.    
IsReadOnly . $
��Auto=�5!      $
��Auto=�5"         Columns 5#      0  *System.Windows.Controls.DataGridTextColumn  5$      ,  &System.Windows.Controls.DataGridColumn   Header$
 Date��6-   1  +System.Windows.Controls.DataGridBoundColumn   Binding 6;   �� $ 
EventDate_� �� StringFormat$ 
yyyy-MM-dd��  5%      $ 
FixingDate��6-    6A   �� $ FixingDate_�$ 
yyyy-MM-dd��  5&      $ CalStart��6-    6?   �� $ CalculationStartDate_�$ 
yyyy-MM-dd��  5'      $ CalEnd��6-    6=   �� $ CalculationEndDate_�$ 
yyyy-MM-dd��4  .System.Windows.Controls.DataGridTemplateColumn  5(      $ PaymentDate��61      CellTemplate 5)      �� 5*   "   .R�5+   &   (  "System.Windows.Controls.DatePicker  $��PaymentDate��61   	   SelectedDate	 6D   �� $ PaymentDate_�
 �� Mode$
 TwoWay=�5,   #   5.        5/      $ Gearing��6-    6>   �� $ Gearing_�  50      $ Spread��6-    6=   �� $ Spread_�53      54      55      56      57      