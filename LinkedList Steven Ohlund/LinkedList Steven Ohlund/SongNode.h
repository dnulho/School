#include <iostream>
using std::string;

#ifndef SN_H
#define SN_H
class SongNode
{
	friend class LibraryList;
public:
	SongNode(string & songTitle, string & artist);
	SongNode(const SongNode & copy);
	SongNode& operator= (const SongNode & rhs);
	~SongNode();

	void Display() const;
	void DisplaySong() const;
	void DisplayArtist() const;
private:
	string m_songTitle;
	string m_artist;

	SongNode * m_next;
	SongNode * m_previous;
};
#endif