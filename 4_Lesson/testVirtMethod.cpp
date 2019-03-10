#include "Passport.h"
#include <random>


static void printInfo(const Id** ids, int idsNum)
{
    if (ids == nullptr) {
        abort();
    }

    for (int i = 0; i < idsNum; ++i) {
        ids[i]->info();
    }
}


static unsigned getRandomVal(int min, int max)
{
    std::random_device rd;
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rd);
}


static unsigned getRandomAge()
{
    return getRandomVal(14, 80);
}


static const char* getRandomName()
{
    const unsigned NAMES_NUM = 200;
    static const char* Names[NAMES_NUM] = {
        "Liam",
        "Emma",
        "Noah",
        "Olivia",
        "William",
        "Ava",
        "James",
        "Isabella",
        "Logan",
        "Sophia",
        "Benjamin",
        "Mia",
        "Mason",
        "Charlotte",
        "Elijah",
        "Amelia",
        "Oliver",
        "Evelyn",
        "Jacob",
        "Abigail",
        "Lucas",
        "Harper",
        "Michael",
        "Emily",
        "Alexander",
        "Elizabeth",
        "Ethan",
        "Avery",
        "Daniel",
        "Sofia",
        "Matthew",
        "Ella",
        "Aiden",
        "Madison",
        "Henry",
        "Scarlett",
        "Joseph",
        "Victoria",
        "Jackson",
        "Aria",
        "Samuel",
        "Grace",
        "Sebastian",
        "Chloe",
        "David",
        "Camila",
        "Carter",
        "Penelope",
        "Wyatt",
        "Riley",
        "Jayden",
        "Layla",
        "John",
        "Lillian",
        "Owen",
        "Nora",
        "Dylan",
        "Zoey",
        "Luke",
        "Mila",
        "Gabriel",
        "Aubrey",
        "Anthony",
        "Hannah",
        "Isaac",
        "Lily",
        "Grayson",
        "Addison",
        "Jack",
        "Eleanor",
        "Julian",
        "Natalie",
        "Levi",
        "Luna",
        "Christopher",
        "Savannah",
        "Joshua",
        "Brooklyn",
        "Andrew",
        "Leah",
        "Lincoln",
        "Zoe",
        "Mateo",
        "Stella",
        "Ryan",
        "Hazel",
        "Jaxon",
        "Ellie",
        "Nathan",
        "Paisley",
        "Aaron",
        "Audrey",
        "Isaiah",
        "Skylar",
        "Thomas",
        "Violet",
        "Charles",
        "Claire",
        "Caleb",
        "Bella",
        "Josiah",
        "Aurora",
        "Christian",
        "Lucy",
        "Hunter",
        "Anna",
        "Eli",
        "Samantha",
        "Jonathan",
        "Caroline",
        "Connor",
        "Genesis",
        "Landon",
        "Aaliyah",
        "Adrian",
        "Kennedy",
        "Asher",
        "Kinsley",
        "Cameron",
        "Allison",
        "Leo",
        "Maya",
        "Theodore",
        "Sarah",
        "Jeremiah",
        "Madelyn",
        "Hudson",
        "Adeline",
        "Robert",
        "Alexa",
        "Easton",
        "Ariana",
        "Nolan",
        "Elena",
        "Nicholas",
        "Gabriella",
        "Ezra",
        "Naomi",
        "Colton",
        "Alice",
        "Angel",
        "Sadie",
        "Brayden",
        "Hailey",
        "Jordan",
        "Eva",
        "Dominic",
        "Emilia",
        "Austin",
        "Autumn",
        "Ian",
        "Quinn",
        "Adam",
        "Nevaeh",
        "Elias",
        "Piper",
        "Jaxson",
        "Ruby",
        "Greyson",
        "Serenity",
        "Jose",
        "Willow",
        "Ezekiel",
        "Everly",
        "Carson",
        "Cora",
        "Evan",
        "Kaylee",
        "Maverick",
        "Lydia",
        "Bryson",
        "Aubree",
        "Jace",
        "Arianna",
        "Cooper",
        "Eliana",
        "Xavier",
        "Peyton",
        "Parker",
        "Melanie",
        "Roman",
        "Gianna",
        "Jason",
        "Isabelle",
        "Santiago",
        "Julia",
        "Chase",
        "Valentina",
        "Sawyer",
        "Nova",
        "Gavin",
        "Clara",
        "Leonardo",
        "Vivian",
        "Kayden",
        "Reagan",
        "Ayden",
        "Mackenzie",
        "Jameson",
        "Madeline"
    };

    return Names[getRandomVal(0, NAMES_NUM)];
}


static void createRandomIds(Id** ids, int idsNum)
{
    for (int i = 0; i < idsNum; ++i) {
        int age = getRandomAge();
        const char* name = getRandomName();
        ids[i] = new Id(name, age);
    }
}


static void createRandomPassports(Id** ids, int num)
{
    for (int i = 0; i < num; ++i) {
        int age = getRandomAge();
        const char* name = getRandomName();
        const char* city = "Moscow";
        ids[i] = new Passport(name, age, city);
    }
}


int main()
{
    int idsNum = 42;
    Id** ids = new Id*[idsNum];

    createRandomIds(ids, idsNum/2);
    createRandomPassports(&(ids[idsNum/2]), idsNum/2);
    printInfo(const_cast<const Id**>(ids), idsNum);
    return 0;
}