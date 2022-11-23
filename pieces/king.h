
enum Colour{white, black};

class King{
    private: 
        Colour pieceColour;
        bool inCheck;
        bool moveValid(const char source_square[], const char destination_square[]);

    public:
        King(Colour pieceColour, bool inCheck);

};