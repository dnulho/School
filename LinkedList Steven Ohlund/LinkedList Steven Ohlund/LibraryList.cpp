#include "LibraryList.h"

LibraryList::LibraryList()
	:m_head(nullptr), m_tail(nullptr)
{
}

LibraryList::~LibraryList()
{
	Purge();
}

void LibraryList::Add(string & songTitle, string & artist)
{
	SongNode * nn = new SongNode(songTitle, artist);
	// If the head is null/empty or the new node is going to be added to front
	if (m_head == nullptr || nn->m_songTitle <= m_head->m_songTitle)
	{
		nn->m_next = m_head;
		m_head = nn;
	}
	else
	{
		SongNode * travel = m_head;
		// Iterate through the list until the new song title goes before the traveling pointer
		// or travel reaches the end of the list
		while (travel != nullptr && travel->m_songTitle < nn->m_songTitle)
		{
			travel = travel->m_next;
		}
		// If the song is being added to the end of the list
		if (travel == nullptr)
		{							 // 1 = node before, 2 = new node
			m_tail->m_next = nn;	 // 1 next points to 2
			nn->m_previous = m_tail; // 2 previous points to 1
			m_tail = nn;			 // tail points to 2
		}
		// If the song is being added in the middle of the list
		else
		{								 // 1 = node before, 2 = new node, 3 = next node in list
			nn->m_previous = travel->m_previous; // 2 previous points to 1
			travel->m_previous->m_next = nn;	 // 1 next points to 2
			travel->m_previous = nn;			 // 3 previous points to 2
			nn->m_next = travel;				 // 2 next points to 3
		}
	}
}

void LibraryList::Delete(string songTitle)
{
	// If list is not empty
	if (m_head != nullptr)
	{
		SongNode * travel = m_head;
		// Move along list until songTitle is found
		while (travel != nullptr && travel->m_songTitle != songTitle)
		{
			travel = travel->m_next;
		}
		// If the song is found
		if (travel != nullptr)
		{								 // 1 = node before, 2 = new node, 3 = next node in list
			travel->m_previous->m_next = travel->m_next;		 // 1 next points to 3
			if (travel->m_next != nullptr)				 // if 3 exists
				travel->m_next->m_previous = travel->m_previous; // 3 previous points to 1
			delete travel;										 // Dealllocate 2
		}
		// If the song is not found do nothing
	}
}

// Remove all elements in list
void LibraryList::Purge()
{
	while (m_head != nullptr)		// While there are elements in the list
	{
		m_head = m_head->m_next;	// Move m_head to the next element
		delete m_head->m_previous;	// Delete the previous element
	}
}						// At the end of this function, m_head is a nullptr

SongNode * LibraryList::FindSong(string songTitle)
{
	SongNode * travel = m_head;
	// Iterate through the list comparing the passed song title with each elements song title
	while (travel != nullptr && travel->m_songTitle != songTitle)
	{
		travel = travel->m_next;
	} // Return pointer to song, or nullptr if not found
	return travel;
}

// Returns a dynamic array with a nullptr endpoint
SongNode ** LibraryList::FindArtist(string Artist)
{
	SongNode * travel = m_head;
	// songList starts with a single nullptr element
	SongNode ** songList = new SongNode*[1]{ nullptr };
	int numSongs = 0;
	while (travel != nullptr) // while there are elments left in the list
	{
		if (travel->m_artist == Artist) // Check to see if the artist is the one we want
		{
			SongNode ** temp = new SongNode*[numSongs + 1];
			for (int ii = 0; ii < numSongs - 1; ii++)
			{
				temp[ii] = songList[ii];
			}
			temp[numSongs - 1] = travel; // add new song to end of list
			temp[numSongs] = nullptr;	 // end array with nullptr
			delete[] songList;
			songList = temp;
			numSongs++;
		}
		travel = travel->m_next;
	}
	return songList;
}