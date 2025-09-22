
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.TreeSet;


class MovieRentingSystem {
    private long key(int shop, int movie) 
    {
        return ((long)shop << 32) | (movie & 0xffffffffL);
    }
    public static class RentedEntry implements Comparable<RentedEntry> 
    {
        int shop;
        int movie;
        int price;
        RentedEntry(int shop, int movie, int price) { this.shop = shop; this.movie = movie; this.price = price; }
        public int compareTo(RentedEntry o) {
            if (this.price != o.price) return Integer.compare(this.price, o.price);
            if (this.shop != o.shop) return Integer.compare(this.shop, o.shop);
            return Integer.compare(this.movie, o.movie);
        }
        @Override public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof RentedEntry)) return false;
            RentedEntry r = (RentedEntry)o;
            return this.shop == r.shop && this.movie == r.movie && this.price == r.price;
        }
        @Override public int hashCode() {
            return Objects.hash(shop, movie, price);
        }
    }
    public static class ShopEntry implements Comparable<ShopEntry>
    {
        int price;
        int shop;
        public ShopEntry(int shop,int price)
        {
            this.price=price;
            this.shop=shop;
        }
        @Override
        public int compareTo(ShopEntry o)
        {
            if(this.price!=o.price)
            {
                return Integer.compare(this.price, o.price);
            }
            return Integer.compare(this.price, o.price);
        }
        @Override
        public boolean equals(Object o)
        {
            if(this==o)
            {
                return true;
            }
            if(!(o instanceof ShopEntry))
            {
                return false;
            }
            ShopEntry et=(ShopEntry)o;
            return et.price==this.price && et.shop==this.shop;
        }
        @Override
        public int hashCode()
        {
            return Objects.hash(shop,price);
        }
    }
    private Map<Integer, TreeSet<ShopEntry>> avail;
    private TreeSet<RentedEntry> rented;
    private Map<Long, Integer> priceMap;
    public MovieRentingSystem(int n, int[][] entries) {
        avail = new HashMap<>();
        rented = new TreeSet<>();
        priceMap = new HashMap<>();

        for (int[] e : entries) 
        {
            int shop = e[0], movie = e[1], price = e[2];
            priceMap.put(key(shop, movie), price);
            avail.computeIfAbsent(movie, k -> new TreeSet<>()).add(new ShopEntry(shop, price));
        }
    }
    
    public List<Integer> search(int movie) {
        List<Integer> res = new ArrayList<>();
        TreeSet<ShopEntry> set = avail.get(movie);
        if (set == null || set.isEmpty()) return res;
        int cnt = 0;
        for (ShopEntry s : set) {
            res.add(s.shop);
            if (++cnt == 5) break;
        }
        return res;
    }
    
    public void rent(int shop, int movie) {
        long k = key(shop, movie);
        Integer price = priceMap.get(k);
        if (price == null) return; 
        TreeSet<ShopEntry> set = avail.get(movie);
        if (set != null) {
            set.remove(new ShopEntry(shop, price));
        }
        rented.add(new RentedEntry(shop, movie, price));
    }
    
    public void drop(int shop, int movie) {
        long k = key(shop, movie);
        Integer price = priceMap.get(k);
        if (price == null) return;
        rented.remove(new RentedEntry(shop, movie, price));
        avail.computeIfAbsent(movie, m -> new TreeSet<>()).add(new ShopEntry(shop, price));
    }
    
    public List<List<Integer>> report() {
        List<List<Integer>> res = new ArrayList<>();
        int cnt = 0;
        for (RentedEntry r : rented) {
            res.add(Arrays.asList(r.shop, r.movie));
            if (++cnt == 5) break;
        }
        return res;
    }
}
class DesignMovieRental
{
    public static void main(String[] args) {
        int n = 3;
        int[][] entries = {{0, 1, 5}, {0, 2, 6}, {0, 3, 7}, {1, 1, 4}, {1, 2, 7}, {2, 1, 5}};
        MovieRentingSystem movieRentingSystem = new MovieRentingSystem(n, entries);
        System.out.println("MovieRentingSystem initialized: " + movieRentingSystem);
    }
}