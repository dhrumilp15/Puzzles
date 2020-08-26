class Solution:
    def solve(self, a, b):
        # Write your code here
        mat = [[0 for idx in range(len(b)+1)] for _ in range(len(a)+1)]

        mat[0] = [0] + [idx for idx in range(1, len(b) + 1)]
        
        for idx in range(1, len(a) + 1):
            mat[idx][0] = idx
        
        for leta in range(1, len(a) + 1):
            for letb in range(1, len(b) + 1):
                dele = mat[leta-1][letb]
                inse = mat[leta][letb-1]
                
                dele += 1
                inse += 1
                
                if mat[leta-1][letb-1] ==0:
                    sub = 0
                else:
                    sub = mat[leta-1][letb-1]
                
                if a[leta - 1] != b[letb - 1]:
                    sub += 1
                
                mat[leta][letb] = min(dele, inse,sub)
        return mat[-1][-1]
                
sol = Solution()
print(sol.solve("zhello", "helli"))
print(sol.solve("cxcezuzoorlxmnumxnsjgcyrhmuigjnwqbftxhvwockcqeiuldgxnkxhgvhjihjitwpqzzrjmdulhxatllbhthveeabumlyfdvnbfuckggmliemawipzmikqyvxacosmzwpkudekfxvugkswpuhoxczomeqmcjoqtvvvxtjkhtqyuzlfuxyizrysclhjxghakahxwmfwwiemirrexnrxzkbxkinghrdivpqgdokavlipkwaqmootdwlcutovbizishefyjueucawudrubheeqqgqdiwseagqpfrgavlhopijckydjzxbdvaaymzyphjdjkdtbqvxcgxjksjwhyarkcllkddvtnnrpulkheksmigcrcujzmikofpgtmdonwtksoozkwaeibwtluqryohewpypuhgaibofajzsfeogehxdsoqtwyejoiqbniyhrfvbshgwopnjotxgiboqmxeacduwibphuqpinaipxtksctrprweuztmxiysjifabhnsvarjeatulgjtwvvdqndjztpjhyxbbwiwdnbmxhnffaqrbnbjiewkdhbekclbboakjwdtcgbanjquluseyzvuztrbxswbhssjguttwiswrbucuvoxfuczoqftecgmpuqlomdyqhsrkebngynlbkhrmuyxaiiueiwbjywepymukyywphurduzinzzedtynhtsjbtfxgvczpxwghicyaumpiyyvvnsdxiuve", "qfoqinbnxyyergqlgeqyaxgsdowgnsszvfmcpuskqxqwzlcfscztmharekzaauoniigckpgqfspwvjcodupmrizhklnamntipcrtrvfrxzyfuzvxqixkqthgfvcckuottwlzprcdkhciuwdzhldogmaczvbviwdcbfmwqhkhqvkmykdhlkfrlmcfbtagddcsuwvaehfczbgindkzfgfwhcbvwefftkjjosdvfuxnirszmduitrmjfxrzpuesgkoinmxrvulzzyswyjizbbnggvgzxjfhiqexqhlajpobpgclbpcnuwizikurviewnktwyvntyrewjgfgudhbihfwbmuyvnxmqmgxiihgkwhzfdeqpgdskldcabidhqqohlvxfvfvafevgrcnnunljtyzgxtwacbhnxycygerguuyudplkotwjhswoefovgkzabicgprexjrvspxjjyukkylzvmbjdetospfoqbaegnpcbzwrwfhxtbonzqxkbogvpoeyrsomidktmijkwdkzggcdxgncbizekvuidmdcmfabrhytxoiyqjkwmkoowvrtonyaionjbluzrkdeqwxtkgiuddnpdjtcezbmcyrisavaocdfxohhvvnmyhmncuieygsnucetwgwflfaeznnrsigapdgagyrolgollznadehbjigwgrrxkkhjjtimfwpfegkdopjzcorbdrgqwcuslgtrcwzcuszfouvpscrqngtmhpwxkegupbhtbkjoxmvtshplhcfrcfpbmcytmmuyohuambs"))