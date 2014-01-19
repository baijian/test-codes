(ns clj-demo.core
  (:use clj-demo.board)
  (:require clj-demo.xors)
  (:gen-class))

(defn seq-demo
  "for and doseq examples"
  []
  (println "for example:")
  (dorun (for [x [:a :b]
               y (range 5) :when (odd? y)]
           (prn x y)))
  (println "doseq example:")
  (doseq [x [:a :b]
          y (range 5) :when (odd? y)]
    (prn x y)))

(defprotocol concatenatable
  (cat [this other]))

;(extend-type String
;  concatenatable
;  (cat [this other]
;    (.concat this other)))

(extend-type java.util.List
  concatenatable
  (cat [this other]
    (concat this other)))

;  (doseq [x (cat "Hello" " World")]
;    (prn x))
;  (doseq [x (cat [1 2 3] [4 5 6])]
;    (prn x))

(defn -main
  "I don't do a whole lot ... yet."
  [& args]
  (clj-demo.xors/image (clj-demo.xors/xyor 4 4))
  ;(prn (clj-demo.board/lookup (clj-demo.board/initial-board) "a1"))
  )

