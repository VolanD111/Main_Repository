star_3 = reviews.loc[reviews.points >= 95 | reviews.country == "Canada"]
star_2 = reviews.loc[85 <= reviews.points < 95]
star_1 = reviews.loc[85 > rewiews.points]
star_ratings = pd.Series({"1"})