import java.util.*;

class FoodRatings {
    private Map<String, TreeSet<String>> cuisineFoods;
    private Map<String, String> cuisineOf;
    private Map<String, Integer> ratingOf;

    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        cuisineFoods = new HashMap<>();
        cuisineOf = new HashMap<>();
        ratingOf = new HashMap<>();

        for (int i = 0; i < foods.length; i++) {
            String food = foods[i];
            String cuisine = cuisines[i];
            int rating = ratings[i];

            cuisineOf.put(food, cuisine);
            ratingOf.put(food, rating);

            cuisineFoods.putIfAbsent(cuisine, new TreeSet<>(
                (a, b) -> ratingOf.get(a).equals(ratingOf.get(b))
                        ? a.compareTo(b)  
                        : ratingOf.get(b) - ratingOf.get(a) 
            ));

            cuisineFoods.get(cuisine).add(food);
        }
    }

    public void changeRating(String food, int newRating) {
        String cuisine = cuisineOf.get(food);
        cuisineFoods.get(cuisine).remove(food); 
        ratingOf.put(food, newRating);
        cuisineFoods.get(cuisine).add(food); 
    }

    public String highestRated(String cuisine) {
        return cuisineFoods.get(cuisine).first();
    }

    public static void main(String[] args) {
        String[] foods = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
        String[] cuisines = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
        int[] ratings = {9, 12, 8, 15, 14, 7};

        FoodRatings fr = new FoodRatings(foods, cuisines, ratings);

        System.out.println(fr.highestRated("korean"));  
        System.out.println(fr.highestRated("japanese")); 

        fr.changeRating("sushi", 16);
        System.out.println(fr.highestRated("japanese")); 

        fr.changeRating("ramen", 16);
        System.out.println(fr.highestRated("japanese")); 
    }
}
v
