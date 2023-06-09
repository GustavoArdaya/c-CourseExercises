// Section 20
// Challenge 2
//  Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
            : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }
    
    bool operator<(const Song &rhs) const  {
        return this->name < rhs.name;
    }
    
    bool operator==(const Song &rhs) const  {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    std::cout << "Playing: " << std::endl;
    std::cout << song << std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    // This function should display the current playlist 
    for (const auto &e : playlist) 
        std::cout << e << std::endl;
    // and then the current song playing.
    std::cout << "Current song: " << std::endl;
    std::cout << current_song << std::endl;
}

int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };
    
    std::list<Song>::iterator current_song = playlist.begin();
    
    // Your program logic goes here
    char selection{};

    do {

        display_menu();

        std::cin >> selection;
        selection = std::toupper(selection);

        switch (selection) {
            case 'F': {
                std::cout << "Playing first song" << std::endl;
                current_song = playlist.begin();
                play_current_song(*current_song); 
            }; break;
            case 'N': {
                std::cout << "Playing next song" << std::endl;
                current_song++;
                if (current_song == playlist.end()) {
                    std::cout << "Wrapping to start of playlist" << std::endl;
                    current_song = playlist.begin();
                }
                play_current_song(*current_song); 
            }; break;
            case 'P': {
                std::cout << "Playing previous song" << std::endl;
                if (current_song == playlist.begin()) {
                    std::cout << "Wrapping to end of playlist" << std::endl;
                    current_song = playlist.end();
                }
                current_song--;
                play_current_song(*current_song); 
            }; break;
            case 'A': {
                std::string name, artist;
                int rating;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Adding and playing a new song" << std::endl;
                std::cout << "Enter song name: ";
                getline(std::cin, name);
                std::cout << "Enter song artist: ";
                getline(std::cin, artist);
                std::cout << "Enter song rating (1-5): ";
                std::cin >> rating;
                playlist.insert(current_song, Song{name, artist, rating});
                current_song--;
                play_current_song(*current_song);
            }; break;
            case 'L': {
                std::cout << std::endl;
                display_playlist(playlist, *current_song);
            }; break;
            case 'Q': {
                std::cout << "Quitting" << std::endl;
            }; break;
            default: {
                std::cout << "Invalid option. Try again." << std::endl;
            }
        }

    } while (selection != 'Q');

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}