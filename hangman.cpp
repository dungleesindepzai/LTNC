/*dungleesin*/
#include <bits/stdc++.h>

#define MAXN 100005
#define MAXM 500005
#define oo 2e9
#define mod 1000000007
#define ll long long
#define FOR(i,a,b)  for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define pii pair<int,int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define vt vector<int>
#define bit(i,x) (x>>i)&1
#define bat(i,x) x|=(1<<i)
#define tat(i,x) x&=(~(1<<i))
#define doi(i,x) x^=(1<<i)
#define checkfile(file) freopen(file".inp", "r",stdin);freopen(file".out","w",stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define START 0
#define GOOD_GUESS 1
#define BAD_GUESS 2
#define MAX_BAD_GUESS 5
using namespace std;

const string word_list[]= {"angle", "ant", "apple", "arch", "arm", "army",
        "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry",
        "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
        "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
        "cake", "camera", "card",  "cart", "carriage", "cat", "chain", "cheese", "chest",
        "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
        "cow", "cup", "curtain", "cushion",
        "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
        "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
        "foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
        "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
        "hospital", "house", "island", "jewel",  "kettle", "key", "knee", "knife", "knot",
        "leaf", "leg", "library", "line", "lip", "lock",
        "map", "match", "monkey", "moon", "mouth", "muscle",
        "nail", "neck", "needle", "nerve", "net", "nose", "nut",
        "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
        "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
        "rail", "rat", "receipt", "ring", "rod", "roof", "root",
        "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
        "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
        "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
        "store", "street", "sun", "table", "tail", "thread", "throat", "thumb", "ticket",
        "toe", "tongue", "tooth", "town", "train", "tray", "tree", "trousers", "umbrella",
        "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm",
};

struct hangman
{
    int bad_guesses;
    string secret_word;
    string guessed_word;
    int hidden_letters;
    int status=START;

    void init(string word)
    {
        secret_word=word;
        guessed_word=string(word.size(),'_');
        bad_guesses=0;
        hidden_letters=word.size();
    }

    void update(char c)
    {
        status=BAD_GUESS;
        for(int i=0;i<secret_word.size();i++)
        {
            if(secret_word[i]==c)
            {
                status=GOOD_GUESS;
                guessed_word[i]=c;
                hidden_letters--;
            }
        }
        if(status==BAD_GUESS) bad_guesses++;
    }

    bool won()
    {
        return (hidden_letters==0);
    }

    bool lost()
    {
        return (bad_guesses>MAX_BAD_GUESS);
    }

    void render()
    {
        if(status==START) cout<<"Start"<<endl;
        else if(status==BAD_GUESS) cout<<"Bad guess!"<<endl;
        else cout<<"Good guess!"<<endl;

        cout<<"Bad guesses: "<<bad_guesses<<endl;
        cout<<"Guessed word: "<<guessed_word<<endl;

        if(won()) cout<<"You won!";
        else if(lost())
        {
            cout<<"You lost!"<<endl;
            cout<<"The secret word is \""<<secret_word<<"\"";
        }
    }

    bool over()
    {
        return (won() || lost());
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    srand(time(0));
    const int random_index=rand() % (sizeof(word_list) / sizeof(string));
    const string secret=word_list[random_index];
    hangman game;
    game.init(secret);
    game.render();
    char input;
    do
    {
        cin>>input;
        game.update(input);
        game.render();
    }
    while(!game.over());
    return 0;
}
