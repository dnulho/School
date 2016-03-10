#define _CRTDBG_MAP_ALLOC
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
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
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	LibraryList music;
	
	switch (Menu())
	{
	case 1:
		SearchBySong(music);
		break;
	case 2:
		SearchByArtist(music);
		break;
	case 3:

		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
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
			<< "8) Exit";
		cin >> select;
		if (select < 1 || select > 8)
		{
			system("cls");
			cout << "Error: Invalid Selection. Please input valid option" << endl;
		}
	}

	return select;
}

void SearchBySong(LibraryList & music) 
{
	string input;
	cout << "What song are you looking for: ";
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
	getline(cin, input);
	const SongNode ** list = music.FindArtist(input);
	if (list != nullptr)
	{
		int ii = 0;
		cout << "Artist: " << input.c_str << endl;
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
	cin >> song;
	cout << "What is the name of the artist: ";
	cin >> artist;
	music.Add(song, artist);
}

void AddBatchSongs(LibraryList & music)
{

}
void Remove1Song(LibraryList & music)
{
	string song;
	cout << "What is the name of the song: ";
	cin >> song;
	music.Delete(song);
}
void RemoveBatchSongs(LibraryList & music)
{

}
void SaveToFile(LibraryList & music)
{

}