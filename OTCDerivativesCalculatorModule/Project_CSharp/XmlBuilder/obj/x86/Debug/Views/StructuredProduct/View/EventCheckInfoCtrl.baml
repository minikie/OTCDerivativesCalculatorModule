   M S B A M L   `   `   `  ����E  AXmlBuilder, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nulla5clr-namespace:XmlBuilder.Views.StructuredProduct.View'XmlBuilder.Views.StructuredProduct.View  5      @    :XmlBuilder.Views.StructuredProduct.View.EventCheckInfoCtrl   5      \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5      R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5      Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5      @d2http://schemas.microsoft.com/expression/blend/2008     5      Dmy5clr-namespace:XmlBuilder.Views.StructuredProduct.View     5      .��5	      � .+�5
   
   ��   �� Orientation$  Vertical=�6   .+�5      �� $  
Horizontal=�6   .+�5      � -   5         �Name$ EventCheck_Grid��5      .+�5      �� $  Vertical=�6!   .+�5      �� $��- EventCheck List��6    &   System.Windows.Controls.DataGrid  5      -   5          Name$ EventCheck_DataGrid��5   #      AutoGenerateColumns .  ��6\   ��  �� Path$ EventCheckViewModel_�   Columns 5      0  *System.Windows.Controls.DataGridTextColumn  5   "   ,  &System.Windows.Controls.DataGridColumn   Header$	 Sym��6S   1  +System.Windows.Controls.DataGridBoundColumn   Binding 65   �� $
 Num_�6S     5   "   $	 Sym��6V    65   �� $ Symbol_�6V     5   "   $
 Name��6T    65   �� $ Name_�6T     5   "   $
 Type��6T    65   �� $ Type_�6T     5   "   $
 Date��6T    65   �� $ Date_�6T     5   "   $ Expired��6W    65   �� $ Expired_�6W   5      �� 5      5      5      � 5      -   5        $ EventCheck_DetailGrid��5      .+�5      �� $  Vertical=�6!   .+�5      � -   5        $# EventIndexTransformation_Grid��5       � DataContext 6F   �� $ EITFVM_�.+�5      �� $  Vertical=�6)   .+�5    "   �� $  
Horizontal=�6-   .+�5!   &   �� $ ��- EventIndexTransformation��6,   �� 5"   &   -   5        $
��Edit��5"   -   6<   5#   #     5$   "   -   5        $ IndexTrans_DataGrid��5$   +    .  ��6H   �� $ IndexTransVMList_� 5%   &     5&   *   $	 Sym��6^    6=   �� $ Symbol_�6^     5'   *   $
 Type��6\    6=   �� $ Type_�6\     5(   *   $ Description��6c    6=   �� $ Description_�6c   5+   #   5,      5-      � 5.      -   5        $ FunctionEventGrid��5.       6:   �� $ FunctionEventVM_�.+�5/      �� $  Vertical=�6)   .+�50   "   �� $  
Horizontal=�6-   .+�51   &   �� $��- FunctionEvent��6,   �� 52   &   $��- JointType : ��6,   �� 53   &   ��6.   �� $ 
JointType_�54   #     56   "    .  ��6+   �� $ EventFunctionMList_� 57   &     58   *   $ 	EventName��6a    6=   �� $ 
EventName_�6a     59   *   $ 	EventType��6a    6=   �� $ 
EventType_�6a     5:   *   $	 Low��6[    6=   �� $
 Low_�6[     5;   *   $ IndexSymbol��6c    6=   �� $ IndexSymbol_�6c     5<   *   $
 High��6\    6=   �� $ High_�6\     5=   *   $ TF��6Z    6=   �� $	 TF_�6Z   5@   #   5A      5B      � 5C      -   5        $ EventDateGrid��5C       66   �� $ EventDateVM_�.+�5D      �� $  Vertical=�6)   .+�5E   "   �� $  
Horizontal=�6-   .+�5F   &   �� $��- EventDate��6,   �� 5G   &   $��	- Type : ��6,   �� 5H   &   	 �� Text$
	 qwqd��6/   5I   #     5J   "    .  ��6+   �� $ EventDates_� 5K   &     5L   *   $
 Date��6[    6=   �� $
 Date�6[     5N   *   $ 	DayOfWeek��6`    6=   �� $ 	DayOfWeek�6`     5O   *   $ Remain��6`    6=   �� $ 	DayOfYear�6`   5S   #   5T      5U      � 5V      -	   5        $ 
PayoffGrid��5V       63   �� $ PayoffListVM_�.+�5W      �� $  Vertical=�6)   .+�5X   "   �� $  
Horizontal=�6-   .+�5Y   &   �� $��- Payoff��6,   �� 5Z   &   -
   5        $
��Edit��5Z   -   6<   5[   #     5\   "    .  ��6+   �� $ PayoffVMList_� 5]   &     5^   *   $
 Type��6\    6=   �� $ Type_�6\     5_   *   $
 Date��6\    6=   �� $ Date_�6\     5`   *   $ Value��6]    6=   �� $ Value_�6]     5a   *   $ Description��6c    6=   �� $ Description_�6c   5d   #   5e      5f      5g      5h      � 5i      -   5        $ DetailInfomation_Grid��5i      .+�5j      �� $  Vertical=�6!   .+�5k      �� $��-Details��6    �� 5l      -   5        
 ��Name$
 txtBox_��5l   "   $��Detail txtBox��63   � 5m      -   5        $ detailCtrl_��5m      5n      5o      5p      5q      5r      5s      