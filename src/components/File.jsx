/**
 *
 * @param {string} name
 * @param {string} image
 * @param {Object} props
 * @returns {JSX.Element}
 * @constructor
 */
export function File({name, image, ...props}) {
    return <div className="file">
        <img src={image} alt={name}/>
        <a href={image}>{name}</a>
    </div>
}
