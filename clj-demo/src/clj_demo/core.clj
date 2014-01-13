(ns clj-demo.core
  (:gen-class))

(defn -main
  "I don't do a whole lot ... yet."
  [& args]
  (for [x [:a :b], y (range 5) :when (odd? y)] [prn x y])
  (doseq [x [:a :b], y (range 5) :when (odd? y)] (prn x y)))
