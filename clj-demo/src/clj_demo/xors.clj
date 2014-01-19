(ns clj-demo.xors)

(defn xyor [max-x max-y]
  (for [x (range max-x) y (range max-y)]
    [x y (bit-xor x y)])
  )

(defn image [l]
  (let [frame (java.awt.Frame.)]
    (.setVisible frame true)
    (.setSize frame (java.awt.Dimension. 200 200))
    (let [gfx (.getGraphics frame)]
      (doseq [[m n xy] l]
        (.setColor gfx (java.awt.Color. xy xy xy))
        (.fillRect gfx m n 1 1)))))
