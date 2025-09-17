import heapq

class FoodRatings:
    def __init__(self, foods, cuisines, ratings):
        self.cuisine_highest = {} 
        self.cuisine_of = {}
        self.rating_of = {}

        for food, cuisine, rating in zip(foods, cuisines, ratings):
            self.cuisine_of[food] = cuisine
            self.rating_of[food] = rating

            if cuisine not in self.cuisine_highest:
                self.cuisine_highest[cuisine] = []

            heapq.heappush(self.cuisine_highest[cuisine], (-rating, food))

    def changeRating(self, food, newRating):
        self.rating_of[food] = newRating
        cuisine = self.cuisine_of[food]
        heapq.heappush(self.cuisine_highest[cuisine], (-newRating, food))

    def highestRated(self, cuisine):
        heap = self.cuisine_highest[cuisine]
        while heap:
            rating, food = heap[0]
            if -rating == self.rating_of[food]:
                return food
            heapq.heappop(heap)


if __name__ == "__main__":
    foods = ["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"]
    cuisines = ["korean", "japanese", "japanese", "greek", "japanese", "korean"]
    ratings = [9, 12, 8, 15, 14, 7]

    fr = FoodRatings(foods, cuisines, ratings)

    print(fr.highestRated("korean"))  
    print(fr.highestRated("japanese"))

    fr.changeRating("sushi", 16)
    print(fr.highestRated("japanese")

    fr.changeRating("ramen", 16)
    print(fr.highestRated("japanese"))
