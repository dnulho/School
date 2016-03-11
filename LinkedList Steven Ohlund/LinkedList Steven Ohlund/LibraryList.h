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

	void SaveAll(ostream & output);

	// Returns nullptr if song not found
	const SongNode * FindSong(string songTitle) const;
	// Returns a dynamic 2d array with a nullptr endpoint
	const SongNode ** FindArtist(string Artist) const;

private:
	SongNode * m_head;
	SongNode * m_tail;
};
#endif
