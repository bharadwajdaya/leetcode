from collections import defaultdict
from typing import List
class Solution:
    def findDuplicate(self,paths: List[str])->List[List[str]]:
        contentOfPath=defaultdict(list)
        for path in paths:
            parts=path.split()
            directory=parts[0]
            for file_info in parts[1:]:
                # print(file_info)
                name,content=file_info.split("(")
                content=content[:-1]
                # full_path=f"{directory}/{name}"
                contentOfPath[content].append(f"{directory}/{name}")

        return [group for group in contentOfPath.values() if len(group)>1]

sol=Solution()
paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"]
sol.findDuplicate(paths)