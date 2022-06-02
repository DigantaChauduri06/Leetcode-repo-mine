/**
 * // Definition for a Node.
 * function Node(val, neighbors) {
 *    this.val = val === undefined ? 0 : val;
 *    this.neighbors = neighbors === undefined ? [] : neighbors;
 * };
 */

/**
 * @param {Node} node
 * @return {Node}
 */
var cloneGraph = function(node) {
    if (!node) return node;
    const mpp = new Map()
    const dfs = (node) => {
        if (mpp.has(node)) return mpp.get(node);
        const nn = new Node(node.val);
        mpp.set(node, nn);
        // Triversing the neighbors
        for (const nei of node.neighbors) {
            const cur = dfs(nei);
            // adjusting the link
            nn.neighbors.push(cur);
        }
        return nn;
    }
    return dfs(node);
};