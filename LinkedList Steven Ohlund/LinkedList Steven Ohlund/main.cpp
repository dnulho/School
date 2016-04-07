#define _CRTDBG_MAP_ALLOC
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <crtdbg.h>

#include "LibraryList.h"
#include "SongNode.h"

int Menu();
void SearchBySong(LibraryList & music);
void SearchByArtist(LibraryList & music);
void Add1Song(LibraryList & music);
void AddBatchSongs(LibraryList & music);
void Remove1Song(LibraryList & music);
void RemoveBatchSongs(LibraryList & music);
void SaveToFile(LibraryList & music);

int main()
{
	bool done = false;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	LibraryList music;
	while (!done)
	{
		switch (Menu())
		{
		case 1:
			SearchBySong(music);
			break;
		case 2:
			SearchByArtist(music);
			break;
		case 3:
			Add1Song(music);
			break;
		case 4:
			AddBatchSongs(music);
			break;
		case 5:
			Remove1Song(music);
			break;
		case 6:
			RemoveBatchSongs(music);
			break;
		case 7:
			SaveToFile(music);
			break;
		case 8:
			done = true;
			break;
		}
	}
	return 0;
}

int Menu()
{
	int select = -1;
	while (select < 1 || select > 8)
	{
		cout << "----------MENU----------\n"
			<< "1) Search for Song\n"
			<< "2) Search for Artist\n"
			<< "3) Add a Song\n"
			<< "4) Add Batch of Songs\n"
			<< "5) Remove a Song\n"
			<< "6) Remove Batch of Songs\n"
			<< "7) Save Songs to list\n"
			<< "8) Exit\n";
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> select;
		system("cls");
		if (select < 1 || select > 8)
		{
			cout << "Error: Invalid Selection. Please input valid option" << endl;
		}
	}
	return select;
}

void SearchBySong(LibraryList & music) 
{
	string input;
	cout << "What song are you looking for: ";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, input);
	const SongNode * song = music.FindSong(input);
	if (song != nullptr)
		song->Display();
	else
		cout << "Song not found" << endl;
}

void SearchByArtist(LibraryList & music)
{
	string input;
	cout << "What Artist are you looking for: ";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, input);
	const SongNode ** list = music.FindArtist(input);
	if (list != nullptr)
	{
		int ii = 0;
		cout << "Artist: " << input.c_str() << endl;
		while (list[ii] != nullptr)
		{
			list[ii]->DisplaySong();
			ii++;
		}
	}
	else
		cout << "Artist not found" << endl;
	delete[] list;
}

void Add1Song(LibraryList & music)
{
	string artist, song;
	cout << "What is the name of the song: ";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, song);
	cout << "What is the name of the artist: ";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin,artist);
	music.Add(song, artist);
}

void AddBatchSongs(LibraryList & music)
{
	string buffer;
	string delimiter("|");
	size_t delimiting_char = -1;

	cout << "What File do you want to read from and add to the list: ";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, buffer);
	ifstream fin(buffer);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			getline(fin, buffer);						// Get next line in format 'song, artist'
			delimiting_char = buffer.find(delimiter);	// Find delimiting point (|) in buffer
			// Add Song/Artist combo to list, using delimiter to split the buffer string between 
			// song and artist.
			music.Add(buffer.substr(0, delimiting_char), buffer.substr(delimiting_char + 1));
						// The +1 accounts for delimiting char
			delimiting_char = -1;		// Revert back to error ready state before next loop
			buffer.clear();
		}
		fin.close();
	}
	else
	{
		cout << "Error: Filename invalid. Returning to Main Menu.\n";
	}
}
void Remove1Song(LibraryList & music)
{
	string song;
	cout << "What is the name of the song: ";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin,song);
	music.Delete(song);
}
void RemoveBatchSongs(LibraryList & music)
{
	string buffer;
	string delimiter("|");
	size_t delimiting_char = -1;

	cout << "What File do you want to read from and remove from the list: ";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, buffer);
	ifstream fin(buffer);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			getline(fin, buffer);						// Get next line in format 'song,artist'
			delimiting_char = buffer.find(delimiter);	// Find delimiting point (|) in buffer
						// Delete Song Title node from list, using delimiter to grab only the title
			music.Delete(buffer.substr(0, delimiting_char));
			
			delimiting_char = -1;		// Revert back to default state before next loop
			buffer.clear();
		}
		fin.close();
	}
	else
	{
		cout << "Error: Could not open File. Returning to Main Menu.\n";
	}
}

void SaveToFile(LibraryList & music)
{
	string buffer;


	cout << "What File do you want to save your list to: ";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, buffer);
	ofstream fout(buffer);
	if (fout.is_open())
	{
		music.SaveAll(fout);
	}
	else
		cout << "Error: Could not open File. Returning to Main Menu.\n";

}