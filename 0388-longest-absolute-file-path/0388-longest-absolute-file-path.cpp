class Solution {
public:
    int lengthLongestPath(string input) {
        unordered_map<int, int> pathLen;  // depth → total length of path till this depth
        int maxLen = 0;

        int i = 0;
        int n = input.length();

        while (i < n) {
            int depth = 0;

            // STEP 1: Count '\t' for depth
            // e.g. if "\t\tfile.ext", then depth = 2
            while (i < n && input[i] == '\t') {
                depth++;
                i++;
            }

            // STEP 2: Read the name until '\n' or end
            int start = i;
            while (i < n && input[i] != '\n') {
                i++;
            }

            // e.g. name = "dir" or "subdir1" or "file.ext"
            string name = input.substr(start, i - start);

            // STEP 3: Move past the '\n' for next iteration
            i++;

            // STEP 4: Check if it's a file (contains '.')
            if (name.find('.') != string::npos) {
                // It's a file

                int fullPathLen;
                if (depth == 0) {
                    // e.g. "file.txt" in root dir
                    fullPathLen = name.length();  // No parent path
                } else {
                    // e.g. "dir/subdir2/file.ext"
                    fullPathLen = pathLen[depth - 1] + 1 + name.length();  // +1 for '/'
                }

                // Update maxLen if this file path is longer
                maxLen = max(maxLen, fullPathLen);
            } else {
                // It's a folder
                if (depth == 0) {
                    // Root-level folder like "dir"
                    pathLen[depth] = name.length();
                    // Example: pathLen[0] = 3 ("dir")
                } else {
                    // e.g. "subdir1" under "dir"
                    pathLen[depth] = pathLen[depth - 1] + 1 + name.length();
                    // Example: pathLen[1] = 3 + 1 + 7 = 11 for "dir/subdir1"
                }
            }
        }

        return maxLen;
    }
};
