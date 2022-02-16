/**
 * @file repeating-playlist.cpp
 * @author nirmeet baweja
 * @brief A playlist is considered a repeating playlist if any of the songs
 * contain a pointer to a previous song in the playlist. Otherwise, the
 * playlist will end with the last song which points to NULL.
 *
 * Implement a function isRepeatingPlaylist that, efficiently with respect to
 * time used, returns true if a playlist is repeating or false if it is not.
 *
 * @version 0.1
 * @date 2022-02-16
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>

bool vector_includes_name(const std::vector<std::string> &names, std::string name)
{
  for (std::string i : names)
  {
    if (i == name)
    {
      return true;
    }
  }
  return false;
}

class Song
{
public:
  Song(std::string name) : name(name), nextSong(NULL) {}

  void next(Song *song)
  {
    this->nextSong = song;
  }

  bool isRepeatingPlaylist()
  {
    std::cout << "Checking is repeating\n";
    std::cout << this->name << '\n';
    static std::vector<std::string> previousSongs;

    Song *currentSong = this;

    while (currentSong->nextSong != NULL)
    {
      std::cout << "current song: " << currentSong->name << '\n';
      if (vector_includes_name(previousSongs, currentSong->name))
      {
        return true;
      }
      previousSongs.push_back(currentSong->name);
      currentSong = currentSong->nextSong;
    }
    return false;
  }

private:
  const std::string name;
  Song *nextSong;
  Song *lastSong;
};

#ifndef RunTests
int main()
{
  Song *first = new Song("Hello");
  Song *second = new Song("Eye of the tiger");
  Song *third = new Song("Some song");

  first->next(second);
  second->next(third);
  third->next(first);

  std::cout << std::boolalpha << first->isRepeatingPlaylist();
}
#endif