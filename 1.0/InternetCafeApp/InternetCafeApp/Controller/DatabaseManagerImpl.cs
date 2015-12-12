﻿using InternetCafeApp.Model;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Windows.UI.Popups;
using SQLite;
using System.Collections.ObjectModel;
namespace InternetCafeApp.Controller
{
    public class DatabaseManagerImpl : DatabaseManager
    {
        private static readonly string _dbPath =
        Path.Combine(
        Windows.Storage.ApplicationData.Current.LocalFolder.Path,"cafe.sqlite");
        ObservableCollection<Room> rooms;
        ObservableCollection<Client> clients;
        ObservableCollection<Record> records;
        ObservableCollection<RecordInt> recordsint;

        public DatabaseManagerImpl()
        { 
            //Default Constructor
            Initialize();
        }
        public void Initialize()
        {
            using (var db = new SQLite.SQLiteConnection(_dbPath))
            {
                db.CreateTable<Room>();
                db.CreateTable<Client>();
                db.CreateTable<Record>();


                int countRoom = db.ExecuteScalar<int>("select count(1) from Room");
                int countClient = db.ExecuteScalar<int>("select count(1) from Client");
                int countRecord = db.ExecuteScalar<int>("select count(1) from Record");

                //Note: This is a simplistic initialization scenario
                if (countRoom == 0)
                {
                    db.RunInTransaction(() =>
                    {
                        db.Insert(new Room()
                        {
                            roomNo = countRoom+1,
                            ipaddress = "192.168.1.1",
                            computerDescription = "new computer",
                            remarks = "no remaks",
                            active = true,
                            isAvailable = true,
                            modDate = new DateTime()
                        });
                        db.Insert(new Room()
                        {
                            roomNo = countRoom+2,
                            ipaddress = "192.168.1.2",
                            computerDescription = "new computer",
                            remarks = "no remaks",
                            active = true,
                            isAvailable = true,
                            modDate = new DateTime()
                        });
                        /*
                        db.Insert(new Client()
                        {
                            description = "i m muzammil peer",
                            imageurl = "",
                            name = "muzammil peer",
                            gender = true,
                            password = "",
                            active = true,
                            lastLogin = new DateTime(),
                            modDate = new DateTime()
                        });*/
                        // Create the tables if they don't exist
                       /* db.Insert(new Record()
                        {
                            active = true,
                            checkIn = new DateTime(),
                            checkOut = new DateTime(),
                            isCardReader = "none",
                            isWebCam = "none",
                            modDate = new DateTime(),
                            oiclient = 1,
                            recievedAmount = 0.0,
                            totalAmount = 10.0,
                        });*/
                    });
                }
                else
                {
                    LoadRoom();
                    LoadClient();
                    LoadRecord();
                    LoadRecordWithInt();
                }
            }
        }
     

        public Task AddRoom(Room obj)
        {
            rooms.Add(obj);

            var connection = new SQLiteAsyncConnection(_dbPath);
            return connection.InsertAsync(obj);
        }

        public async Task<ObservableCollection<Room>> LoadRoom()
        {
            var list = new ObservableCollection<Room>();
            var connection = new SQLiteAsyncConnection(_dbPath);

            rooms = new ObservableCollection<Room>(
               await connection.QueryAsync<Room>(
                     "select * from Room"));
            return rooms;
        }

        public Task RemoveRoom(Room obj)
        {
            rooms.Remove(obj);

            var connection = new SQLiteAsyncConnection(_dbPath);
            return connection.DeleteAsync(obj);
        }

        public Task UpdateRoom(Room obj)
        {
            var oldRoom = rooms.FirstOrDefault(
                c => c.oiroom == obj.oiroom);

            if (oldRoom == null)
            {
                throw new System.ArgumentException(
                        "Room not found.");
            }
            rooms.Remove(oldRoom);
            rooms.Add(obj);

            var connection = new SQLiteAsyncConnection(_dbPath);
            return connection.UpdateAsync(obj);
        }

        public Task AddClient(Client obj)
        {
            clients.Add(obj);

            var connection = new SQLiteAsyncConnection(_dbPath);
            return connection.InsertAsync(obj);
        }

        public async Task<ObservableCollection<Client>> LoadClient()
        {
            var list = new ObservableCollection<Client>();
            var connection = new SQLiteAsyncConnection(_dbPath);

            clients = new ObservableCollection<Client>(
               await connection.QueryAsync<Client>(
                     "select * from Client"));
            return clients;
        }

        public Task RemoveClient(Client obj)
        {
            clients.Remove(obj);

            var connection = new SQLiteAsyncConnection(_dbPath);
            return connection.DeleteAsync(obj);
        }

        public Task UpdateClient(Client obj)
        {
            var oldClient = clients.FirstOrDefault(
                c => c.oiclient == obj.oiclient);

            if (oldClient == null)
            {
                throw new System.ArgumentException(
                        "Client not found.");
            }
            clients.Remove(oldClient);
            clients.Add(obj);

            var connection = new SQLiteAsyncConnection(_dbPath);
            return connection.UpdateAsync(obj);
        }

        public Task AddRecord(Record obj)
        {
            records.Add(obj);

            var connection = new SQLiteAsyncConnection(_dbPath);
            return connection.InsertAsync(obj);
        }

        public async Task<ObservableCollection<Record>> LoadRecord()
        {
            var list = new ObservableCollection<Record>();
            var connection = new SQLiteAsyncConnection(_dbPath);

            records = new ObservableCollection<Record>(
               await connection.QueryAsync<Record>(
                     "select * from Record"));
            return records;
        }
        public async Task<ObservableCollection<RecordInt>> LoadRecordWithInt()
        {
            var list = new ObservableCollection<RecordInt>();
            var connection = new SQLiteAsyncConnection(_dbPath);
            
            recordsint = new ObservableCollection<RecordInt>(
               await connection.QueryAsync<RecordInt>(
                     "select r.oirecord,substr('ms-appx:///Assets/List/' || r.oirecord || '.png',1,50) Image ,c.name,c.gender,ro.roomNo ,r.checkIn ,r.checkOut, r.isWebCam, r.isCardReader, r.totalAmount, r.recievedAmount, r.active, r.modDate  from Record r inner join Room ro on (r.oiroom=ro.oiroom) inner join Client c on (r.oiclient=c.oiclient)"));
            return recordsint;
        }

        public Task RemoveRecord(Record obj)
        {
            records.Remove(obj);

            var connection = new SQLiteAsyncConnection(_dbPath);
            return connection.DeleteAsync(obj);
        }

        public Task UpdateRecord(Record obj)
        {
            var oldRecord = records.FirstOrDefault(
                c => c.oirecord == obj.oirecord);

            if (oldRecord == null)
            {
                throw new System.ArgumentException(
                        "Record not found.");
            }
            records.Remove(oldRecord);
            records.Add(obj);

            var connection = new SQLiteAsyncConnection(_dbPath);
            return connection.UpdateAsync(obj);
        }
    }
}
