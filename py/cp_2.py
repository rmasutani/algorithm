import sys

def backtrack(idx, ings, recipe_names, recipe_ings, acc, res):
    """
    ings: コマンドラインから与えられるもの
    recipes: txtから読み込むもの
    """
    # base case
    # 食材を使いきれていない場合
    if idx >= len(recipe_names) and len(ings) != 0:
        # 残りの食材で作ることが出来るものがあるかどうかを確認する
        
        for i in range(len(recipe_names)):
            found = 0

            for r in ings: # ingsが残り物
                if r in recipe_ings[i]:
                    found += 1

            if found == len(recipe_ings[i]):
                return
        
        # 何も作れなければ出力に追加
        res.append(acc)
        return 
    

    if idx >= len(recipe_names) or len(ings) == 0:
        res.append(acc)
        return

    # 訪問中のレシピを採用する場合 (出来ない場合は除く)
    # match ingredients
    found = 0
    unused = []
    for r in ings:
        if r in recipe_ings[idx]:
            found += 1
            continue
        unused.append(r)
    
    
    if found == len(recipe_ings[idx]): # 必要な食材をカバーできているかの確認
        
        backtrack(idx+1, unused, recipe_names, recipe_ings, acc+[recipe_names[idx]], res)
    

    # 採用しない場合
    backtrack(idx+1, ings, recipe_names, recipe_ings, acc, res) # 食材を使わないので訪問中のレシピは選択されない

    
    


def main():
    # input = sys.stdin.readline
    path = "recipes.txt"
    ings = list(set(sys.argv[1:]))
    # ings_len = len(ings)
    with open(path) as f:
        recipes = f.readlines()

    recipes_sp = list(map(lambda x: x.rstrip().split(": "), recipes))

    recipe_names = [r[0] for r in recipes_sp]
    recipe_ings = [r[1].rstrip().split(" ") for r in recipes_sp]

    # print(recipe_names)
    # print(recipe_ings)

    
    # バックトラック
    res = []
    ans = backtrack(0, ings, recipe_names, recipe_ings, [], res)

    for c in res:
        print(", ".join(c))


if __name__ == '__main__':
    main()
    