/**
 *
 * @param {string} name
 * @param {string} image
 * @param {Object} props
 * @returns {JSX.Element}
 * @constructor
 */
export function Folder({name, image, ...props}) {
    return <div className="folder">
        <img src={image} alt={name}/>
        <a href={image}>{name}</a>
    </div>
}
