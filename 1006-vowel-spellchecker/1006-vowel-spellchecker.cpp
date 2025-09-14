// Priority as given=>
// 1. Exact Match
// 2. Capitalization error match
// 3. Vowel error match

// for exact match -> make a set of the words..match directly..O(1)
// for Capitalization error -> have an map where elements => (tolower(string) ->
// string) ..then match accordingly

// for vowel error match -> have an vowelMap and store elements in small cases
// with '*' in place of vowel characters ..for the query words..make lower..try
// to match with other case..if not..convert the vowel characters into '*'..then
// match with this
class Solution {
public:
    unordered_set<string> exactSet;
    unordered_map<string, string> caseMap;
    unordered_map<string, string> vowelMap;

    string toLowerWord(string& s) {
        string result = s;
        for (char& ch : result) {
            ch = tolower(ch);
        }

        return result;
    }

    string replaceVowel(string& s) {
        string result = s;
        for (char& ch : result) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                ch = '*';
        }

        return result;
    }

    string checkForMatch(string& query) {
        if (exactSet.count(query))
            return query;

        // Capitalization error check
        string lowerCase = toLowerWord(query);
        if (caseMap.count(lowerCase))
            return caseMap[lowerCase];

        // Vowel error check
        string vowelCase = replaceVowel(lowerCase);
        if (vowelMap.count(vowelCase))
            return vowelMap[vowelCase];

        return "";
    }

    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        exactSet.clear();
        caseMap.clear();
        vowelMap.clear();

        for (string word : wordlist) {
            exactSet.insert(word);

            string lowerCase = toLowerWord(word);
            if (caseMap.find(lowerCase) == caseMap.end())
                caseMap[lowerCase] = word;

            string vowelCase = replaceVowel(lowerCase);
            if (vowelMap.find(vowelCase) == vowelMap.end())
                vowelMap[vowelCase] = word;
        }

        vector<string> result;
        for (auto& query : queries) {
            result.push_back(checkForMatch(query));
        }

        return result;
    }
};