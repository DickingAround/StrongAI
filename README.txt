* Learn patterns, learn them slowly.
* Start with basic NN and run a  Back-prop (but on a sparse network)

I have the idea of doing the ocil problem. But how would a NN solve it? how to make a NN do clustering. BP requires a desired outcome. Or at least to know if the outcome you got is closer or farther from good or bad. 

Pushing all outcome away from 0? It could push them all negative. 
In a way it needs to remember them all and try to divide them. run through all the instances you've seen and try to make distinctions. If that's just the 4, you'll look at the main differences. If that's a thousand of 4 categories, you could make a thousand categories. Or you could make 4 or some number inbeteen.

Let's say we know it has to be 4. What then? Four outputs and you have to light one and only one of them. DOesn't matter which one. 

This is the first test:
* OCIL
* Two outputs 
* Run the NN with BP where you ask every item to light one and only one of the outputs.
* This will prove that it can be done without *strict* classes (still, need to know how many classes, just not which ones)


How do we actually do back-prop? And is our use of sparse NNs going to work?
Take a NN and work back into the weights of the things that lead in. I think it's actually fine to do it this way, but it'll be hard to think about with the transition, we'll need a clear diff.

what could a weak AI solve for you? Financial management? There are many day-to-day problems. But a strong AI is going to have to learn and evolve to live on it's own. No teaching. Just independant learning
.

Where to begin finding the patterns in the first place. Perhaps the first step is clustering the examples. Like we always cluster the pixels in the image first. What images just natually look like eachother. THen as we NN, we try to also do those clusters. That's okish.

How about this, we don't even wnat to do character recognition. We want to notice that characters are indeed characters. We want to learn it from scratch. To notice they're the same. In the end, this machine is 100% unstructured learning.

So, our next step is to learn about clustering algorithms. But for now, let's continue with NNs and deepness. How do I get a NN to do clustering? 

Well, the NN has to give a shit. People give a shit. THey learn toward goals. They especially like outcomes, what they can change.

This machine will have to learn to twiddle with things. It tries changing things, just looking for when it makes a change. It's actually more like a toddler; looking to affect the environment in a predictable way. But now this is totally different, this is figuring out the options for actions to get to a plan. I thought we were just observing and learning. Isn't the best learning with interaction? Yes, but less scalable. 

We could try to create and auto-hacker. You give it the basic tools and it iterates through options and styles, etc. 

Thing is, only real soure of data in the world is the internet. But why. why not robot bodies? Why not a video feed? We can scale, we just need many of them.

Back to lettering; can I do it without free will? Probably. SO let's do that. There are so many ways that things can be alike.

Let's go simple, still using BP. WHat is a happy case the NN learns back from? A degree of certainty. Like if there are A,B,C,D we want to create levels of division. To learn a heiarchy. We can start by literally learning a tree, like making sure it's giving similar outputs for 2 of them and maximally dissimlar outputs for the difference between the 2 clusters of 2. 

Would it just try to maximize some of the ratings? Pick a pixel and go wild on it? It'll ahve to see lots of examples. and then make a small number of clusters. SO we could show it a ton of 0s and Cs and 1s and ls. It should pick up and cluster them like my mind does. 

So we use NNs with back-prop but how do we tell BP what 'good' is for a single example? give an example, run it foreward, get an outcome. No. Give it more than one example, watch it say similar or different. But now we have four different paths. We're re-leanringthe same pattern 4 times. We must do it on one path.

It could compare to memory. Literally the exact same set of NNs being run more than once but with another layer on top that's combining them. Isn't that the same as running them all again? Could take the average results knowing the real data points. But that doens't prove much since you're introing you knowledge of the intended outcome. 

We make a NN which has so many nodes that there's essentially static at the end. Every letter looks like every other letter. We BP to move every letter away from static. But in which direction? How do we know the right direction? is it enough to just begin moving it away from where we are? In theory that should move others away from where we are. But we're talking about output nodes, nodes that give binary answers. 

We make it deep. many levels. And within the nodes of each level we try to have them move their settings away from eachother. push all the settings away from 0.

But can't it easily do this by adding static?  Imagine this NN output node, it's near 0 and knows it must move away. so what does it do? It picks whatever signal input is strongest and just upps it. 

(A website called 'shit I already tried')

How about start with a new structure of learning.
We know of recurrent neural networks. But what about deep networks that discover patterns within themselves? We know that people stack NNs but I don't know how exatly. I know they look at different parts of a photo sometimes.
What's a situation where there are categories? Objects, of course. But how do humans do this similarizing? Could we have it make those categoies and thus make it not only summarizeable but also more intelligent to new data? Like if it sees letters, and some have circles in them. It should notice that there's this pattern that is circle. 
Right now, it essentially finds them by chance. THe back-propigation moves conections within a single node toward that node having some meaning. But not all nodes do have meaning. I think this is part of the 'brain dammage' algorithms. How do I find that meaning and enhance it? How do I turn it into a clear problem?

We have BP already. We have brain dammage already. Say we train one, then in the middle of training we're doing brain dammage and restoration. Have a sort of evolutionary competition of which connections are making the difference (not just BP).
Well what is a sub-problem in this way? It's when they solve their own problem. What is their problem? Looking for any kind of pattern. Why not include clustering? So the inputs are actually clustered first? What does that even mean? CLustering is on the per-object-ot-learn basis. We're trying.. to cluster the signals? What signals appear together? Not quite, since they're all in context. 

Imagine an image that's moved to one corner. Or finding the 'o's in the image. What we want is more like something that can notice that pixels in the image often appear together. Or frankly the NN should have some sense of the placement and structure of those pixels. 

We can't hardly give them meta-data. Can we string regular NNs together? How can get give the sub-NNs a goal? What is their goal really? To look for patterns. How does clustering look for patterns? Patterns on the inputs, like things Y and X are often seen together. Maybe make the NN deep and then find places within the interior which are agreeing with the output? Not quite the same.

how do I teach a computer ot 'look for differences' to find sub-differences instead of learning the final pattern. I could force it by making the NN deep but then having summary points. Perhaps I should expect to learn slower at first but faster later? That is how people learn; we learn slower to develop the patterns. 

Does having a small number of pre-nodes show you the pattern? I could kind of prove this by learning a bunch of letters and then seeing if it can learn numbers faster? Showing it learned some deeper pattern (like seeing curves or some shit).

The pre-nodes is only part of the issue. They create the structure for it but will BP really learn it? Look, the brain has to do this somehow. There's some per-node structure that does this. Not an over-arching system. 

That's all one strategy. Another option is literally just to try and make a machine that plans. Like we know there's A* style exploring algorithms. what would it need to plan? Without goals, or actions, there is no 'planning'. Yea, fuck that for now. 
