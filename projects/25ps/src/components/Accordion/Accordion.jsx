import React, { useState } from 'react'
import data from './data'

const Accordion = () => {
  const [selected, setSelected] = useState(null)
  const [multiSelect, setMultiSelect] = useState(false)
  const [multiple, setMultiple] = useState([])

  const handleSelected = (id) => {
    setSelected(selected === id ? null : id)
  }

  const handleMulti = (id) => {
    let copyList = [...multiple]
    const multi = copyList.indexOf(id)
    if (multi === -1) {
      copyList.push(id)
    } else {
      copyList.splice(multi, 1)
    }
    setMultiple(copyList)
  }

  return (
    <div>
      <button onClick={() => setMultiSelect(!multiSelect)}>Toggle</button>
      <div>
        {data && data.length > 0 ? (
          data.map((item) => (
            <div>
              <div
                onClick={
                  multiSelect
                    ? () => handleMulti(item.id)
                    : () => handleSelected(item.id)
                }
              >
                <h3>{item.question}</h3>
                <span>+</span>
              </div>
              {multiSelect
                ? multiple.indexOf(item.id) !== -1 && <div>{item.answer}</div>
                : selected === item.id && <div>{item.answer}</div>}
            </div>
          ))
        ) : (
          <div>No Data Found!!!</div>
        )}
      </div>
    </div>
  )
}

export default Accordion
