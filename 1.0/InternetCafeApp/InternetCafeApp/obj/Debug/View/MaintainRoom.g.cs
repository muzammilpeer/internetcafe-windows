

#pragma checksum "E:\Documents\Visual Studio 2012\Projects\InternetCafeApp\InternetCafeApp\View\MaintainRoom.xaml" "{406ea660-64cf-4c82-b6f0-42d48172a799}" "135BE85AFC649C2AEB440D61FCDAD662"
//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace InternetCafeApp.View
{
    partial class MaintainRoom : global::Windows.UI.Xaml.Controls.Page, global::Windows.UI.Xaml.Markup.IComponentConnector
    {
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("Microsoft.Windows.UI.Xaml.Build.Tasks"," 4.0.0.0")]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
 
        public void Connect(int connectionId, object target)
        {
            switch(connectionId)
            {
            case 1:
                #line 78 "..\..\View\MaintainRoom.xaml"
                ((global::Windows.UI.Xaml.Controls.Primitives.ButtonBase)(target)).Click += this.btnSave_Click;
                 #line default
                 #line hidden
                break;
            case 2:
                #line 79 "..\..\View\MaintainRoom.xaml"
                ((global::Windows.UI.Xaml.Controls.Primitives.ButtonBase)(target)).Click += this.btnCancel_Click;
                 #line default
                 #line hidden
                break;
            case 3:
                #line 85 "..\..\View\MaintainRoom.xaml"
                ((global::Windows.UI.Xaml.Controls.Primitives.Selector)(target)).SelectionChanged += this.comboBoxRooms_SelectionChanged;
                 #line default
                 #line hidden
                break;
            case 4:
                #line 42 "..\..\View\MaintainRoom.xaml"
                ((global::Windows.UI.Xaml.Controls.Primitives.ButtonBase)(target)).Click += this.GoBack;
                 #line default
                 #line hidden
                break;
            case 5:
                #line 129 "..\..\View\MaintainRoom.xaml"
                ((global::Windows.UI.Xaml.Controls.Primitives.ButtonBase)(target)).Click += this.btnRefresh_Click;
                 #line default
                 #line hidden
                break;
            case 6:
                #line 130 "..\..\View\MaintainRoom.xaml"
                ((global::Windows.UI.Xaml.Controls.Primitives.ButtonBase)(target)).Click += this.btnHelp_Click;
                 #line default
                 #line hidden
                break;
            case 7:
                #line 124 "..\..\View\MaintainRoom.xaml"
                ((global::Windows.UI.Xaml.Controls.Primitives.ButtonBase)(target)).Click += this.btnEdit_Click;
                 #line default
                 #line hidden
                break;
            case 8:
                #line 125 "..\..\View\MaintainRoom.xaml"
                ((global::Windows.UI.Xaml.Controls.Primitives.ButtonBase)(target)).Click += this.btnRemove_Click;
                 #line default
                 #line hidden
                break;
            case 9:
                #line 126 "..\..\View\MaintainRoom.xaml"
                ((global::Windows.UI.Xaml.Controls.Primitives.ButtonBase)(target)).Click += this.btnAdd_Click;
                 #line default
                 #line hidden
                break;
            }
            this._contentLoaded = true;
        }
    }
}


