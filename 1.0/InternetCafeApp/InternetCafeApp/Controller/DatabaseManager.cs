﻿using InternetCafeApp.Model;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InternetCafeApp.Controller
{
    public interface DatabaseManager
    {
        //Room Table
        Task AddRoom(Room obj);
        Task<ObservableCollection<Room>> LoadRoom();
        Task RemoveRoom(Room obj);
        Task UpdateRoom(Room obj);

        //Client Table
        Task AddClient(Client obj);
        Task<ObservableCollection<Client>> LoadClient();
        Task RemoveClient(Client obj);
        Task UpdateClient(Client obj);

        //Record Table
        Task AddRecord(Record obj);
        Task<ObservableCollection<Record>> LoadRecord();
        Task<ObservableCollection<RecordInt>> LoadRecordWithInt();
        Task RemoveRecord(Record obj);
        Task UpdateRecord(Record obj);
    }
}
