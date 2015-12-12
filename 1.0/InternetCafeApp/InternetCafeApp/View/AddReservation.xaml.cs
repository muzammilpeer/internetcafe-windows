using InternetCafeApp.Controller;
using InternetCafeApp.Model;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

namespace InternetCafeApp.View
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class AddReservation : Page
    {
        private DatabaseManager data = new DatabaseManagerImpl();
        private ViewModel _vm;

        public AddReservation()
        {
            this.InitializeComponent();
            comboxClientName.IsEnabled = true;
            txtName.IsEnabled = false;
            _vm = new ViewModel(data);
            _vm.SelectedItemClient = new Client();
            _vm.SelectedItemRecord = new Record();

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

        private void GoBack(object sender, RoutedEventArgs e)
        {
            this.Frame.GoBack();
        }

        private void btnSave_Click(object sender, RoutedEventArgs e)
        {
            Record newRecord = new Record();
            Client newClient = new Client();

            if (!comboxClientName.IsEnabled)
            {
                newClient.oiclient = _vm.Clients.Count() + 1;
                newClient.name = txtName.Text;
                newClient.gender = tgGender.IsOn;
                newClient.active = true;
                newClient.modDate = DateTime.Now;
                newClient.lastLogin = DateTime.Now;
                _vm.AddClient(newClient);


                newRecord.oiclient = newClient.oiclient;
                newRecord.oiroom = _vm.SelectedItemRoom.oiroom;
                newRecord.active = true;
                newRecord.checkIn = DateTime.Now; // DateTime.TryParse(txtCheckIn.Text);
                newRecord.checkOut = DateTime.Now; // DateTime.TryParse(txtCheckOut.Text);
                newRecord.isCardReader = chkCardReader.IsChecked.ToString();
                newRecord.isWebCam = chkWebCam.IsChecked.ToString();
                newRecord.modDate = DateTime.Now;
                newRecord.oirecord = _vm.Records.Count() + 1;
                _vm.AddRecord(newRecord);

            }
            else
            {
                newRecord.oiclient = _vm.SelectedItemClient.oiclient;
                newRecord.oiroom = _vm.SelectedItemRoom.oiroom;
                newRecord.active = true;
                newRecord.checkIn = DateTime.Now; // DateTime.TryParse(txtCheckIn.Text);
                newRecord.checkOut = DateTime.Now; // DateTime.TryParse(txtCheckOut.Text);
                newRecord.isCardReader = chkCardReader.IsChecked.ToString();
                newRecord.isWebCam = chkWebCam.IsChecked.ToString();
                newRecord.modDate = DateTime.Now;
                newRecord.oirecord = _vm.Records.Count() + 1;
                _vm.AddRecord(newRecord);

            }
        }

        private void btnCancel_Click(object sender, RoutedEventArgs e)
        {

        }

        private void comboBoxRooms_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {

        }

        private void comboxClientName_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {

        }

        private void btnAddName_Click(object sender, RoutedEventArgs e)
        {
            comboxClientName.IsEnabled = false;
            txtName.IsEnabled = true;
        }
    }
}
