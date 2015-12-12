using InternetCafeApp.Controller;
using InternetCafeApp.Model;
using InternetCafeApp.View;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Popups;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Media.Animation;
using Windows.UI.Xaml.Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

namespace InternetCafeApp
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        private DatabaseManager data = new DatabaseManagerImpl();
        private ViewModel _vm;

        public MainPage()
        {
            this.InitializeComponent();
            _vm = new ViewModel(data);

            _vm.Initialize();
            DataContext = _vm;
        }

        /// <summary>
        /// Invoked when this page is about to be displayed in a Frame.
        /// </summary>
        /// <param name="e">Event data that describes how this page was reached.  The Parameter
        /// property is typically used to configure the page.</param>
        protected override void OnNavigatedTo(NavigationEventArgs e)
        {

        }


        private void AddReservation_Click(object sender, RoutedEventArgs e)
        {
            this.Frame.Navigate(typeof(AddReservation));

          //  this.listRooms.ItemsSource = controller.getListRoom();
        }
        private void Save_Click(object sender, RoutedEventArgs e)
        {
            Room cust = new Room
            {
                roomNo = 1,
                ipaddress = "192.168.1.1",
                computerDescription = "new computer",
                remarks = "no remaks",
                active = true,
                isAvailable = true,
                modDate = new DateTime()
            };

            _vm.AddRoom(cust);
        }

        private void Delete_Click(object sender, RoutedEventArgs e)
        {
          /*  if (_vm.SelectedItem != null)
            {
                _vm.DeleteRoom(_vm.SelectedItem);
            }*/
        }

        private void Settings_Click(object sender, RoutedEventArgs e)
        {
            /*
            List<String> localDataSource = new List<String>();
            for (int i = 0; i < 5; i++)
            {
                localDataSource.Add("item " + i);
            }

            //this.listRooms.ItemsSource = localDataSource;
            try
            {
                var dbpath = Path.Combine(Windows.Storage.ApplicationData.Current.LocalFolder.Path, "data.db3");
                using (var db = new SQLite.SQLiteConnection(dbpath))
                {
                    var d = from x in db.Table<Person>() select x;
                    listRooms.Items.Clear();
                    foreach (var sd in d)
                    {
                        this.listRooms.Items.Add(sd.name.ToString());
                    }
                    db.Dispose();
                    db.Close();
                }
            }
            catch
            {
            }
            */
        }
       

        private void listRooms_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
           // this.Frame.Navigate(typeof(AddReservation));
        }

        private void AddReport_Click(object sender, RoutedEventArgs e)
        {
            this.Frame.Navigate(typeof(Reports));
        }

        private void MaintainRoom_Click(object sender, RoutedEventArgs e)
        {
            this.Frame.Navigate(typeof(MaintainRoom));
        }

        private void MaintainRecord_Click(object sender, RoutedEventArgs e)
        {
//            this.Frame.Navigate(typeof(MaintainRecord));
            this.Frame.Navigate(typeof(ListRecords));
        }

        private void btnMaintainClient_Click(object sender, RoutedEventArgs e)
        {
            this.Frame.Navigate(typeof(MaintainClient));
        }

        private void btnAddPayment_Click(object sender, RoutedEventArgs e)
        {
            this.Frame.Navigate(typeof(AddPayment));
        }

        private void btnAdd_Click(object sender, RoutedEventArgs e)
        {

        }

        private void btnSettings_Click(object sender, RoutedEventArgs e)
        {
            this.Frame.Navigate(typeof(Settings));
        }

        private void btnHelp_Click(object sender, RoutedEventArgs e)
        {

        }

       
    }
}
