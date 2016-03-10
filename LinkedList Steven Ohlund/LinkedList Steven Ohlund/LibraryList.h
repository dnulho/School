#include "SongNode.h"

#ifndef LL_H
#define LL_H
class LibraryList
{	
public:
	LibraryList();
	~LibraryList();
	
	void Add(string & songTitle, string & artist);

	void Delete(string songTitle);
	void Purge();

	// Returns nullptr if song not found
	SongNode * FindSong(string songTitle);
	// Returns a dynamic 2d array with a nullptr endpoint
	SongNode ** FindArtist(string Artist);

private:
	SongNode * m_head;
	SongNode * m_tail;
};
#endif
