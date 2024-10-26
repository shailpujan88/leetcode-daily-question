/*
   Function: removeSubfolders
   Purpose: Given a list of folder paths, remove any subfolders, retaining only the main folders.
   
   Pseudocode:
   1. Sort the list of folder paths alphabetically to ensure subfolders appear immediately after their parent folders.
   2. Initialize a result vector to hold only the main folders.
   3. Add the first folder from the sorted list to the result, as it cannot be a subfolder.
   4. For each remaining folder:
      a. Check if it starts with the last added folder in the result vector (indicating it’s a subfolder).
      b. If it’s not a subfolder, add it to the result vector.
   5. Return the result vector containing only main folders.
*/

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Step 1: Sort folders alphabetically
        sort(folder.begin(), folder.end());

        // Step 2: Initialize result vector and add the first folder
        vector<string> result{folder[0]};

        // Step 3: Iterate through folders starting from the second element
        for (int i = 1; i < folder.size(); i++) {
            // Step 4a: Append '/' to last folder in result for subfolder check
            string lastFolderWithSlash = result.back() + '/';

            // Step 4b: Add current folder if it doesn’t start with the last folder in result
            if (folder[i].compare(0, lastFolderWithSlash.size(), lastFolderWithSlash) != 0) {
                result.push_back(folder[i]);
            }
        }

        // Step 5: Return result containing main folders only
        return result;
    }
};
