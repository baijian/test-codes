(ns clj-demo.core
  (:gen-class))

(defn -main
  "I don't do a whole lot ... yet."
  [& args]
  (println "for example:")
  (dorun (for [x [:a :b]
               y (range 5) :when (odd? y)]
           (prn x y)))
  (println "doseq example:")
  (doseq [x [:a :b]
          y (range 5) :when (odd? y)]
    (prn x y)))
