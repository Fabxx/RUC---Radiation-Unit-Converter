#include <iostream>
#include <cmath>
#include <cstring>

//TODO: add micro and milli per hour
class units
{
    public:
    double n;
    inline double RoentgenToSievertH();
    inline double SievertToRoentgenH();
    inline double SievertToRem();
    inline double mRoentgenTomSievert();
    inline double mSievertTomRoentgen();
};

//Roentgen per hour to Sievert per Hour.
inline double units::RoentgenToSievertH()
{
    return this->n * 100;
}

inline double units::SievertToRoentgenH()
{
    return this->n / 100;
}

//Sievert to REM.
inline double units::SievertToRem()
{
    return this->n * 100;
}

inline double units::mRoentgenTomSievert()
{
    return this->n * 0.0093296636656249;
}

int main(int argc, char *argv[])
{
    units *obj = new units();
    obj->n = atof(argv[3]);

    if (argv[1] == NULL)
    {
        std::cout << "Usage: ./main <initial_unit> <final_unit> <number>\n"
                  << "Units per hour (normal):\n"
                  << "1) R   (Roentgen)\n"
                  << "2) Sv  (Sievert)\n"
                  << "Units per hour (milli)\n"
                  << "3) mR  (milli roentgen)\n"
                  << "4) mSv (milli sieverts)\n"
                  << "Not timed units\n"
                  << "rem (rontgen equivalent man)\n"
                  << "Available conversions:\n"
                  << "Roentgen/h to Sievert/h\t Sievert/h to Roentgen/h\n"
                  << "milli roentgen/h to milli Sieverts/h\t milli Sieverts/h to roentgen/h\n"
                  << "rem to sieverts\tsieverts to rem." << std::endl;  
        return 0;
    }
    
    //make lowercase the strings on each position, and store them on the exact same position.
    for (size_t i = 0;  i < strlen(argv[1]); ++i) {
        argv[1][i] = tolower(argv[1][i]);
    }
    
    for (size_t i = 0; i < strlen(argv[2]); ++i) {
        argv[2][i] = tolower(argv[2][i]);
    }
    
    
    if ((strcmp(argv[1], "r") == 0) && (strcmp(argv[2], "sv") == 0))
    std::cout << "Sievert/h from Roentgen/h: " << obj->RoentgenToSievertH() << std::endl;
    if ((strcmp(argv[1], "sv") == 0) && (strcmp(argv[2], "r") == 0))
    std::cout << "Roentgen/h from Sievert/h: " << obj->RoentgenToSievertH() << std::endl;
    if ((strcmp(argv[1], "sv") == 0) && (strcmp(argv[2], "rem") == 0))
    std::cout << "rem from Sievert:" << obj->SievertToRem() << std::endl;
    if ((strcmp(argv[1], "mr") == 0) && (strcmp(argv[2], "msv") == 0))
    std::cout << "milli Sieverts from milli Roentgen:" << obj->mRoentgenTomSievert() << std::endl;
    
    delete obj;
    return 0;
}
